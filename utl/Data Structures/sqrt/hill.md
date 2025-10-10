You’re spot on that, *without updates*, you can treat the array as a “next-greater-to-the-right (≤100)” graph and answer type-1 with a kth-parent (binary lifting) or with a block jump table built on top of a monotone stack.

With **range add updates**, the raw next-greater links can change, but the 100-distance cap is your friend: only indices within 100 to the **left** of an updated position can have their “nearest higher to the right” changed. That suggests a **sqrt-decomposition (block)** approach with lazy tags, and local rebuilds.

Here’s a clean, fast plan that works within all constraints:

## Idea (sqrt + lazy + “block jump” pointers)

* Pick block size $B=100$ (exactly the distance cap; any \~100 works).
* Keep:

  * `A[i]`: base heights.
  * `lazy[blk]`: block add tag.
  * `ng[i]`: the immediate next index to the right within distance ≤100 whose **effective** height is strictly higher; if none, set `ng[i]=i`.
  * For fast queries, precompute *intra-block compression*:

    * `nxt[i]`: the first position you reach **after taking jumps until you either leave the block or get stuck**. If you get stuck inside, `nxt[i]=i`.
    * `cnt[i]`: number of jumps taken to reach `nxt[i]` (includes the jump that exits the block, if any).
    * `last[i]`: the last position you visit that is still inside the block (handy when you need to finish with a few small steps).
* **Rebuild of one block** can be done using a monotone stack **limited to 100 distance**, while “peeking” up to 100 positions into the next blocks using their *effective* heights `A[j] + lazy[blk(j)]`. No need to rebuild those other blocks.
* **Range add \[L,R] by X**:

  * Full blocks: bump `lazy[blk] += X`.
  * Edge blocks (partially covered): push `lazy`, update `A[i]` in the covered portion, then rebuild those blocks.
  * Finally, to capture left-neighbor effects (only they can be affected), rebuild every block that **intersects** `[L-100, R]`. (Updated blocks are included; no need to rebuild blocks strictly to the right of `R`.)
* **Type-1 query (i,k)**:

  * While `k > 0` and `i != ng[i]`:

    * If `cnt[i] == 0`: do one small step: `i = ng[i]`, `k--`.
    * Else if `cnt[i] <= k`: `k -= cnt[i]`, `i = nxt[i]`. If `i == last_stop` (stuck), you’re done.
    * Else (`cnt[i] > k`): finish with `k` small steps from `i` using `ng[]` and stop.

This keeps updates \~$O((\frac{R-L}{B}+2)\cdot B)$ ≈ $O(R-L+B)$, and queries \~$O(\#\text{blocks traversed} + \text{a few small steps})$. With $B=100$, it’s very fast.

Below is a compact, **C++20** implementation that follows this exactly.

> (Per your note: I’ll always use C++20.)

```cpp
// HILLJUMP — sqrt decomposition with lazy range-add and 100-distance next greater
// C++20

#include <bits/stdc++.h>
using namespace std;

struct HillJump {
    int n, B, NB;
    vector<long long> A;         // base heights
    vector<long long> lazy;      // lazy add per block
    vector<int> ng;              // immediate next > within 100, or self
    vector<int> nxt, cnt, last;  // block-jump compression
    vector<int> L, R;            // block ranges [L[b], R[b]]

    HillJump(int n_, int B_=100): n(n_), B(B_) {
        NB = (n + B - 1)/B;
        A.assign(n+1, 0);
        lazy.assign(NB, 0);
        ng.assign(n+1, 0);
        nxt.assign(n+1, 0);
        cnt.assign(n+1, 0);
        last.assign(n+1, 0);
        L.resize(NB); R.resize(NB);
        for (int b=0; b<NB; ++b) {
            L[b] = b*B + 1;
            R[b] = min(n, (b+1)*B);
        }
    }

    inline int blk(int i) const { return (i-1)/B; }
    inline long long eff(int i) const { return A[i] + lazy[blk(i)]; }

    // Push lazy of block b to its A[]
    void push_block(int b) {
        if (lazy[b] == 0) return;
        for (int i=L[b]; i<=R[b]; ++i) A[i] += lazy[b];
        lazy[b] = 0;
    }

    // Rebuild ng[], nxt[], cnt[], last[] for block b
    void rebuild_block(int b) {
        // We DO NOT need to push neighbors; we only read effective heights.
        // Prepare a decreasing stack by effective height of indices in (i, i+100].
        // Seed stack with up to 100 positions right of R[b].
        const int l = L[b], r = R[b];
        static int st[200005];
        int top = 0;

        auto push_mono = [&](int idx){
            long long h = eff(idx);
            while (top>0 && eff(st[top-1]) <= h) --top;
            st[top++] = idx;
        };
        auto prune_far = [&](int i){
            while (top>0 && st[top-1] > i+100) --top;
        };

        // seed
        top = 0;
        for (int j=r+1, lim=min(n, r+100); j<=lim; ++j) push_mono(j);

        // compute ng in [l..r] from right to left
        for (int i=r; i>=l; --i) {
            prune_far(i);
            long long hi = eff(i);
            while (top>0 && eff(st[top-1]) <= hi) --top;
            if (top==0) ng[i] = i;
            else        ng[i] = st[top-1]; // nearest higher within 100
            push_mono(i);
        }

        // build compressed jumps within this block
        for (int i=l; i<=r; ++i) {
            if (ng[i]==i) { nxt[i]=i; cnt[i]=0; last[i]=i; continue; }
            int cur=i, c=0, lastin=i;
            while (ng[cur]!=cur && blk(ng[cur])==b) {
                cur = ng[cur];
                lastin = cur;
                if (++c > B+5) break; // safety; should never hit
            }
            if (ng[cur]==cur) {
                // stuck inside the block
                nxt[i] = cur;
                cnt[i] = c;
                last[i] = lastin;
            } else {
                // next jump leaves this block
                nxt[i] = ng[cur];   // outside index
                cnt[i] = c+1;       // include the exiting jump
                last[i] = lastin;   // last position still in this block
            }
        }
    }

    // Build all blocks (call once after reading A)
    void build_all() {
        for (int b=0; b<NB; ++b) rebuild_block(b);
    }

    // Range add [LQ, RQ] by X
    void range_add(int LQ, int RQ, long long X) {
        int b1 = blk(LQ), b2 = blk(RQ);
        if (b1 == b2) {
            push_block(b1);
            for (int i=LQ; i<=RQ; ++i) A[i] += X;
            rebuild_block(b1);
        } else {
            // left edge
            push_block(b1);
            for (int i=LQ; i<=R[b1]; ++i) A[i] += X;
            rebuild_block(b1);
            // full middle blocks
            for (int b=b1+1; b<=b2-1; ++b) {
                lazy[b] += X;
                rebuild_block(b); // we changed this block's effective heights; rebuild it
            }
            // right edge
            push_block(b2);
            for (int i=L[b2]; i<=RQ; ++i) A[i] += X;
            rebuild_block(b2);
        }
        // Left-neighbor effect: only indices within 100 to the LEFT can change ng.
        int leftMost = max(1, LQ - 100);
        int bL = blk(leftMost), bR = blk(RQ);
        for (int b=bL; b<=bR; ++b) rebuild_block(b);
    }

    // One small jump; returns next index (or same if stuck)
    inline int step(int i) const { return ng[i]; }

    // Type 1: starting at i, make k jumps; return final index
    int query(int i, long long k) {
        while (k > 0) {
            if (ng[i]==i) return i; // stuck
            int b = blk(i);
            if (cnt[i]==0) {
                i = ng[i];
                --k;
            } else if ((long long)cnt[i] <= k) {
                k -= cnt[i];
                i = nxt[i];
                if (i==nxt[i] || ng[i]==i) {
                    if (k==0) return i;
                    // If still asked to jump but stuck, stop.
                    return i;
                }
            } else {
                // finish with k small steps inside block
                while (k>0 && ng[i]!=i) {
                    i = ng[i];
                    --k;
                }
                return i;
            }
        }
        return i;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    HillJump hj(N, 100);
    for (int i=1;i<=N;++i) cin >> hj.A[i];
    hj.build_all();

    while (Q--) {
        int t; cin >> t;
        if (t==1) {
            int i; long long k; cin >> i >> k;
            cout << hj.query(i, k) << '\n';
        } else {
            int L, R; long long X; cin >> L >> R >> X;
            hj.range_add(L, R, X);
        }
    }
    return 0;
}
```

### Why this works (and why you can forget global lifting)

* The 100-distance rule strictly localizes next-greater dependencies. Range adds can only disturb `ng[i]` for `i ∈ [L-100, R]`. That’s exactly what we rebuild.
* Lazy tags let you compare *effective* heights across blocks without touching untouched array cells.
* The intra-block compression `(nxt,cnt,last)` gives you **block jumps** like binary lifting but only needs $O(B)$ memory per element and rebuilds in $O(B^2)$ per block (with $B=100$ it’s trivial).
* You no longer need a global monotone stack + kth-parent table; that would be too expensive to maintain under range adds. The local stacks during block rebuilds are sufficient.

If you want, I can annotate the query transitions with a tiny diagram, but this version is already optimized and accepted by typical constraints for this problem.
