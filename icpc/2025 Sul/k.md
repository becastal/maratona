Here’s a linear‑time/O(N) solution.  The key is to notice that you only ever “push” a block of at most 13 computers (the internal‐push case) or you “break off” one computer at the head (the head‐push case).  You keep track of your layout as a linked list of “runs” of 1’s, each tagged with how many 0’s follow it.  Repeatedly:

1. **Merge** any two adjacent runs if their separating gap has shrunk to 0.
2. **Drop** the front run if it’s length ≤1 (no adjacency there).
3. Otherwise you have a run of length L≥2 with a positive gap g after it.

   * If L>14, do an **internal push**: split it into

     * a left run of length L–13 (gap =1),
     * a right run of length 13 (gap =old g).
       This costs 1.
   * Else (L≤14), do a **head push**: you can break off up to min(L–1, g) adjacencies in one go, so you subtract

     ```cpp
     ll d = L-1;
     ll h = min(d, g);
     cost += h;
     L -= h;
     g -= h;
     ```

     and update your run from (L, g) to (L–h, g–h).

Keep iterating until the list is empty (all runs are length ≤1 and all gaps >0).  Every merge/split/drop is O(1), and there are O(N) initial runs plus O(total\_ones/13) splits, so it runs in O(N) time and uses O(N) memory.

Here’s a compact C++20 implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    // 1) extract runs of 1's and the zeros that follow each
    vector<ll> runs, gaps;
    int i = 0;
    while (i < N) {
        while (i < N && s[i] == '0') ++i;
        if (i >= N) break;
        ll run = 0;
        while (i < N && s[i] == '1') {
            ++run;
            ++i;
        }
        runs.push_back(run);
        ll z = 0;
        while (i < N && s[i] == '0') {
            ++z;
            ++i;
        }
        gaps.push_back(z);
    }
    if (runs.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    // 2) we pad an "infinite" gap after the last run:
    const ll INF = N;          // N is big enough (>= any needed head‐push)
    gaps.back() = INF;

    // 3) build a doubly‐linked list of (run_length, gap_after)
    list<pair<ll,ll>> segs;
    for (int j = 0; j < (int)runs.size(); j++) {
        segs.emplace_back(runs[j], gaps[j]);
    }

    ll cost = 0;
    // 4) greedy loop
    while (!segs.empty()) {
        // 4a) merge any two runs at front whose gap has shrunk to 0
        auto it = segs.begin();
        while (true) {
            if (it == segs.end()) break;
            auto it2 = next(it);
            if (it2 == segs.end()) break;
            if (it->second != 0) break;
            // merge it and it2
            it->first  += it2->first;
            it->second  = it2->second;
            segs.erase(it2);
        }

        // 4b) drop a run of length < 2
        it = segs.begin();
        if (it->first < 2) {
            segs.erase(it);
            continue;
        }

        // 4c) now front run has length L>=2 and gap g>0
        ll L = it->first;
        ll g = it->second;

        if (L > 14) {
            // internal push: split off a block of 13
            cost += 1;
            ll old_gap = g;
            it->first  = L - 13;   // left piece
            it->second = 1;        // gap we just created
            auto it2 = next(it);
            segs.insert(it2, { 13, old_gap });
        } else {
            // head push: we can break off up to min(L-1, g) adjacencies at once
            ll d = L - 1;        // total adjacencies in this run
            ll h = min(d, g);
            cost += h;
            it->first  = L - h;
            it->second = g - h;
        }
    }

    cout << cost << "\n";
    return 0;
}
```

### Why this works

* **Any push** either splits off exactly 13 trailing computers (the internal case when the run is “too big” to head‐push) or splits off up to `L–1` computers at the front (when `L≤14`, the head‐push case).
* We always operate on the **leftmost** violation (the first place you see `11`), and we batch as many head‐pushes as we can into a single subtraction `h = min(L–1, gap)`.
* Whenever the gap between two runs goes to zero, we **merge** them immediately, since they have become consecutive again.
* Once all runs are length ≤1 and all gaps >0, there are no more `11`’s anywhere, so we’re done.

This runs in **O(N)** total time for an input of length up to 10⁶, and uses only standard C++20.
