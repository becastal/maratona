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
	int n, m; cin >> n >> m;

	vector<int> v(n), ruins, M;
	vector<ll> pre(n+1, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pre[i+1] = v[i] + pre[i];

		if (v[i] <= m) ruins.push_back(i);
		if (v[i] == m) M.push_back(i);
	}

	ll res = 0;
	for (int i = 0; i < (int)ruins.size(); i++) {
		if (v[ruins[i]] != m) continue;

		int l = i ? ruins[i-1]+1 : 0;
		int r = i != (int)ruins.size()-1 ? ruins[i+1] : n;

		//cout << l << ' ' << r << ": " << pre[r] - pre[l] << endl;
		res = max(res, pre[r] - pre[l]);
	}

	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
