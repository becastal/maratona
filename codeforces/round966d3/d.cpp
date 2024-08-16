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
	int n; cin >> n;
	vector<int> v(n);
	vector<ll> pre(n + 1, 0);
	for (int& i : v) cin >> i;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + v[i - 1];

	vector<char> s(n);
	for (char& c : s) cin >> c;

	int r = n - 1;
	ll res = 0;
	for (int l = 0; l < n and l < r; l++) {
		if (s[l] != 'L') continue;
		while (r >= 0 and s[r] == 'L') {
			r--;
		}

		//cout << l << ' ' << r << endl;
		if (l < r) res += (pre[r + 1] - pre[l]);
		r--;
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
