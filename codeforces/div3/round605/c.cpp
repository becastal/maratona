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

int solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<int> bom(26, 0);
	for (int i = 0; i < k; i++) {
		char c; cin >> c;
		bom[c-'a'] = 1;
	}

	ll res = 0;
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		if (!bom[s[l]-'a']) continue;

		while (r < n and bom[s[r]-'a']) {
			r++;
		}

		res += (ll) (r - l + 1) * (r - l) / 2;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
