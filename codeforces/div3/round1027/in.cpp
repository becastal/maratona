#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAX = 1'000'000 + 5;
static int spf[MAX]; // smallest prime factor up to MAX

// Build a sieve so that spf[n] = smallest prime dividing n (for 2 ≤ n ≤ MAX-1).
static void build_sieve(int N) {
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            // i is prime
            for (ll j = (ll)i; j <= N; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

// Recursively factor n into the vector `out` (in non-decreasing order).
static void factor_rec(vector<int>& out, int n) {
    if (n == 1) return;
    int p = spf[n];
    factor_rec(out, n / p);
    out.push_back(p);
}

// Given x ≤ 10^6, return a sorted (non-decreasing) list of its prime factors.
static vector<int> factor_list(int x) {
    if (x == 1) return {};
    vector<int> out;
    factor_rec(out, x);
    return out;
}

//----------------------------------------------------------------------------------------
// We want a function that, given a small multiset of primes `a[0..m-1]`
// and a capacity `k`, returns the minimum number of bins needed so that
// each bin’s product ≤ k.  We do a DFS‐based bin‐packing with pruning.
//
// In the worst case m ≤ ~20 (since any number ≤ 10^6 has at most ~20 prime‐factors
// if you count multiplicities).  The naive O(2^m·m) DP can be as large as ~20×2^20 ≈ 20 million
// per call, which is borderline if it happens a few times.  Instead, we do backtracking
// with these optimizations:
//  1) “Sort `a` in descending order” so large primes go first (strong pruning).
//  2) Maintain a global `best` = current best solution (initially = m).
//  3) At each step `idx`, if `bins.size() ≥ best`, prune immediately.
//  4) Whenever you try to place a[i] into existing bins, skip bins with identical contents
//     (i.e.\ skip “seen” bin‐products) to avoid symmetric branches. 
//
// This typically runs in a few microseconds when m ≤ 14, and still under 1 ms for m ≤ 20.
//
static int globalBest;
static int   m_glob;
static ll    K_glob;
static int   items_glob[25]; // up to ~20–22 primes

// bins_glob stores the current product in each open bin.
static ll bins_glob[25];      
static int  binCount_glob;

// idx = current index in items_glob[0..m_glob-1] that we must place.
static void dfs_pack(int idx) {
    if (idx == m_glob) {
        // placed all items; record a new best:
        globalBest = min(globalBest, binCount_glob);
        return;
    }
    // Prune: if we've already opened ≥ globalBest bins, no need to continue.
    if (binCount_glob >= globalBest) return;

    ll v = items_glob[idx];

    // We will try to place v into each existing bin, if it fits.
    // Use a local “seen” set to avoid putting v into two bins that currently
    // have the same product—this skips symmetric branches.
    unordered_set<ll> seen;
    for (int b = 0; b < binCount_glob; b++) {
        ll curProd = bins_glob[b];
        if (curProd * v <= K_glob) {
            if (seen.count(curProd)) {
                // Another bin has exactly the same product; skipping to avoid symmetry.
                continue;
            }
            seen.insert(curProd);

            // Place v in bin b
            bins_glob[b] = curProd * v;
            dfs_pack(idx + 1);
            // backtrack
            bins_glob[b] = curProd;

            // Another small pruning: if we placed v into an empty bin (i.e. we do
            // “bins_glob[b]==v” and b was effectively unused so far), there is no
            // point in trying further empty bins.  But in this loop we only iterate
            // up to binCount_glob, and if b < binCount_glob then it’s not an empty bin anyway.
        }
    }

    // Finally, try opening a brand‐new bin containing only v.
    // But again, if we already tried to put v in “an empty‐equivalent” (i.e. had a bin
    // with product=1), we would have recorded 1 in `seen`.  However, by construction
    // we never keep bins with product=1 in bins_glob (we only create bins when we put
    // something inside), so there is no risk of duplicating an “empty‐bin” branch here.
    //
    bins_glob[binCount_glob++] = v;
    dfs_pack(idx + 1);
    binCount_glob--;
}

// A wrapper.  Input: a vector<int> “a” of primes, and an integer k.
// Return: the minimum #bins so that each bin’s product ≤ k.
// If any single prime > k, return +∞ (INT_MAX) immediately.
static int minBins(vector<int>& a, int k) {
    int m = (int)a.size();
    if (m == 0) return 0;
    for (int p : a) {
        if (p > k) return INT_MAX;
    }
    sort(a.rbegin(), a.rend()); // place large primes first

    m_glob = m;
    K_glob = (ll)k;
    for (int i = 0; i < m; i++) {
        items_glob[i] = a[i];
    }

    globalBest = m;    // “worst” is each prime in its own bin
    binCount_glob = 0; // no bin opened yet
    dfs_pack(0);
    return globalBest;
}
//----------------------------------------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_sieve(MAX - 1);

    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        // Factor x and y by peeling off spf[]
        vector<int> fx_all = factor_list(x);
        vector<int> fy_all = factor_list(y);

        // Build frequency‐maps, subtract common gcd‐exponents
        unordered_map<int,int> cntx, cnty;
        for (int p : fx_all) cntx[p]++;
        for (int p : fy_all) cnty[p]++;

        // Subtract the common primes:
        for (auto &pr : cntx) {
            int prime = pr.first;
            int ex    = pr.second;
            if (cnty.count(prime)) {
                int ey = cnty[prime];
                int common = min(ex, ey);
                cntx[prime] -= common;
                cnty[prime] -= common;
            }
        }

        // Rebuild the leftover‐prime lists fx_list, fy_list
        vector<int> fx_list, fy_list;
        fx_list.reserve(fx_all.size());
        fy_list.reserve(fy_all.size());

        for (auto &pr : cntx) {
            int prime = pr.first, ex = pr.second;
            while (ex--) fx_list.push_back(prime);
        }
        for (auto &pr : cnty) {
            int prime = pr.first, ey = pr.second;
            while (ey--) fy_list.push_back(prime);
        }

        // If any leftover prime exceeds k, it is impossible right away:
        bool impossible = false;
        for (int p : fx_list) if (p > k) impossible = true;
        for (int p : fy_list) if (p > k) impossible = true;
        if (impossible) {
            cout << -1 << "\n";
            continue;
        }

        // Now do two separate “bin‐pack” calls: one on fx_list (division steps),
        // and one on fy_list (multiplication steps).
        int needDivOps  = minBins(fx_list, k);
        int needMultOps = minBins(fy_list, k);

        if (needDivOps == INT_MAX || needMultOps == INT_MAX) {
            // Should not happen, since we already checked “p > k” above, but guard anyway:
            cout << -1 << "\n";
        } else {
            cout << (needDivOps + needMultOps) << "\n";
        }
    }
    return 0;
}

