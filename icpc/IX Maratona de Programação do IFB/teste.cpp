#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// count of trailing zeros in m!
ll tz(ll m) {
    ll res = 0;
    for (ll p = 5; p <= m; p *= 5)
        res += m / p;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    cin >> n;

    // if you want the smallest m with tz(m!) >= n,
    // you only need to search up to 5*n
    ll l = 0, r = 5 * n, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (tz(mid) >= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    // now `ans` is the first m with tz(m!) >= n
    // but we only want exactly n zeros
    if (ans != -1 && tz(ans) == n) {
        cout << ans << "\n";
    } else {
        cout << "-1\n";   // or whatever “no-solution” you prefer
    }

    return 0;
}

