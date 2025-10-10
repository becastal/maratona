#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAX = (ll)1e12 + 10;
vector<ll> T;

int solve() {
    ll n; 
    if (!(cin >> n)) return 0;

    // 1) n is triangular?
    if (binary_search(T.begin(), T.end(), n)) {
        cout << 1 << '\n';
        return 0;
    }

    // 2) n is sum of two triangular numbers? (allowing same number twice)
    auto it_end = upper_bound(T.begin(), T.end(), n);   // only need T[i] <= n
    if (it_end != T.begin()) {
        size_t l = 0;
        size_t r = size_t(it_end - T.begin() - 1);
        while (l <= r) {
            __int128 sum = (__int128)T[l] + T[r]; // avoid accidental overflow
            if (sum == n) {
                cout << 2 << '\n';
                return 0;
            } else if (sum > n) {
                --r;
            } else {
                ++l;
            }
        }
    }

    // 3) otherwise
    cout << 3 << '\n';
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute triangular numbers up to MAX.
    // Include T0 = 0 for convenience.
    T.push_back(0);
    for (ll i = 1, s = 0; s <= MAX; ++i) {
        s += i;
        T.push_back(s);
    }

    int t = 1;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
