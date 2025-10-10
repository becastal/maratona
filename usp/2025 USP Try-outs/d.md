You’re on the right track thinking about residues. The key observation is:

* For a fixed $M$, the number of rounds you need is exactly the number of **distinct residues** among $\{A_i \bmod M\}$.
* If **all** $A_i$ are congruent modulo $M$, you need just **1** round. That happens iff $M$ divides **every pairwise difference**.

Let
$G = \gcd(|A_2-A_1|, |A_3-A_1|, \dots, |A_N-A_1|)$.

### What’s the minimum number of rounds?

* If $G \ge 2$, you can pick any $M>1$ with $M\mid G$. Then all $A_i \equiv A_1 \pmod M$ ⇒ **minimum is 1**.
* If $G = 1$, no $M>1$ can make all residues equal ⇒ **minimum is 2** (and $M=2$ always achieves it because both parities appear when $G=1$).

So the answer is **almost never 1**, unless those differences share a non-trivial gcd.

### How many $M$ achieve that minimum?

* If minimum is **1**: any $M>1$ dividing $G$ works.
  Count $= \tau(G)-1$ (number of divisors of $G$ excluding 1).
  Special case: if **all** $A_i$ are equal, every $M\in\{2,\dots,10^9\}$ works ⇒ count $=10^9-1$.

* If minimum is **2** (i.e., $G=1$): we must count those $M>1$ for which the set $\{A_i \bmod M\}$ has **exactly two** residues. Here’s a clean, fast way to do it:

  If such an $M$ exists, the array splits into two congruence classes modulo $M$. At least one class has size $\ge 2$. Pick two **anchors** (say the first two elements). For any valid $M$, at least one anchor belongs to a class of size $\ge 2$, hence $M$ divides the difference between that anchor and some other element.
  Therefore, **every valid $M$** must divide $|A_i-A_{anchor}|$ for **some** $i$.

  Algorithm:

  1. Collect candidate $M$ as **all divisors $>1$** of the differences $|A_i-A_{0}|$ and $|A_i-A_{1}|$ (two anchors suffice; the only exception is $N=2$ with consecutive numbers, which we special-case).
  2. For each candidate $M$, actually compute how many distinct residues $\{A_i\bmod M\}$ appear, with early exit if you see 3 residues. Count those with exactly 2.
  3. Edge case $N=2$ and $|A_1-A_2|=1$: **every** $M>1$ yields 2 distinct residues ⇒ count $=10^9-1$.

This is fast in practice: you only factor differences from two anchors (at most $2(N-1)$ numbers $\le 10^9$); divisor enumeration is $O(\sqrt{d})$ per difference, and you deduplicate candidates. Checking each $M$ is $O(N)$ with early stop at 3 residues.

---

Here’s a complete C++20 implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static const int64 M_MAX = 1'000'000'000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    vector<int64> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        // One seal: always 1 round; any M>1 works.
        cout << 1 << ' ' << (M_MAX - 1) << '\n';
        return 0;
    }

    // Compute G = gcd of differences to A[0]
    int64 G = 0;
    for (int i = 1; i < N; ++i) G = std::gcd(G, llabs(A[i] - A[0]));

    // All equal?
    bool all_equal = true;
    for (int i = 1; i < N; ++i) if (A[i] != A[0]) { all_equal = false; break; }
    if (all_equal) {
        cout << 1 << ' ' << (M_MAX - 1) << '\n';
        return 0;
    }

    auto tau = [&](int64 x) -> long long {
        // number of positive divisors of x
        long long res = 1;
        for (int64 p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) { x /= p; ++cnt; }
                res *= (cnt + 1);
            }
        }
        if (x > 1) res *= 2;
        return res;
    };

    if (G > 1) {
        // Minimum rounds = 1. Count Ms = divisors of G excluding 1.
        cout << 1 << ' ' << (tau(G) - 1) << '\n';
        return 0;
    }

    // Now G == 1 -> minimum rounds = 2
    // Special-case N==2 and consecutive numbers: every M>1 yields 2 residues.
    if (N == 2 && llabs(A[1] - A[0]) == 1) {
        cout << 2 << ' ' << (M_MAX - 1) << '\n';
        return 0;
    }

    // Helper: add divisors (>1) of d into candidates
    auto add_divisors = [&](int64 d, vector<int64>& out) {
        if (d <= 1) return;
        for (int64 i = 2; i * i <= d; ++i) {
            if (d % i == 0) {
                out.push_back(i);
                int64 j = d / i;
                if (j != i) out.push_back(j);
            }
        }
        out.push_back(d); // include d itself
    };

    // Build candidate Ms from differences to two anchors (indices 0 and 1).
    vector<int64> cand;
    cand.reserve(200000);
    cand.push_back(2); // M=2 always gives 2 residues when G==1

    auto process_anchor = [&](int idx) {
        // Avoid reprocessing identical difference values for this anchor
        unordered_set<int64> seen;
        seen.reserve(1024);
        for (int i = 0; i < N; ++i) if (i != idx) {
            int64 d = llabs(A[i] - A[idx]);
            if (d > 1 && !seen.count(d)) {
                seen.insert(d);
                add_divisors(d, cand);
            }
        }
    };
    process_anchor(0);
    if (N >= 2) process_anchor(1);

    // Deduplicate candidates and keep only 2..1e9
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    cand.erase(remove_if(cand.begin(), cand.end(), [&](int64 m){ return m < 2 || m > M_MAX; }), cand.end());

    auto residues_is_two = [&](int64 M)->bool {
        // Track up to two residues; early stop on third
        int64 r1 = LLONG_MIN, r2 = LLONG_MIN;
        for (int i = 0; i < N; ++i) {
            int64 r = ((A[i] % M) + M) % M;
            if (r == r1 || r == r2) continue;
            if (r1 == LLONG_MIN) { r1 = r; continue; }
            if (r2 == LLONG_MIN) { r2 = r; continue; }
            return false; // third distinct residue
        }
        // Here there is at most 2 residues; since G==1 it cannot be 1 residue for any M>1
        return (r1 != LLONG_MIN && r2 != LLONG_MIN);
    };

    long long countM = 0;
    for (int64 M : cand) {
        if (residues_is_two(M)) ++countM;
    }

    cout << 2 << ' ' << countM << '\n';
    return 0;
}
```

### Why two anchors are enough (for $G=1$)

If some $M$ yields exactly two residues, at least one residue class has size $\ge 2$.

* If both classes have size $\ge 2$, **every** anchor is in a multi-element class.
* If one class is a singleton, then among the first two elements, **at least one** is in the big class.

For the anchor that lies in a multi-element class, $M$ must divide the difference between that anchor and **some** other element of the same class. Therefore $M$ appears among the divisors of a difference to one of the two anchors, and our candidate set is complete. We then verify each candidate by actually counting residues (early-stop at 3).
