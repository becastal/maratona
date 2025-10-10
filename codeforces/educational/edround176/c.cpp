#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
    int n, m; 
    cin >> n >> m;
    vector<ll> v(m);
    for (ll& i : v) cin >> i, i = min(i, (ll)n-1);

    sort(v.begin(), v.end());
    vector<ll> pre(m+1, 0);
    for (int i = 1; i <= m; i++) {
        pre[i] = pre[i-1] + v[i-1];
    }

	//ll res = 0;
	//for (int i = 0; i < m; i++) {
	//	for (int j = i+1; j < m; j++) {
	//		if (v[i] + v[j] - n < 0) continue;
	//		res += 1 + (v[i] + v[j] - n);
	//	}
	//}
	//cout << 2 * res << endl;

    ll res = 0;
    for (int i = 1; i < m; i++) {
        int j = lower_bound(v.begin(), v.begin() + i, n - v[i]) - v.begin();
        if (j < i) {
            ll cnt = i - j;
            res += (pre[i] - pre[j]) + cnt * (v[i] - n + 1);
        }
    }
    cout << 2 * res << endl;
}

int main()
{
    _;
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

