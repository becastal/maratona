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
	int n; cin >> n;
	string s; cin >> s;

	vector<vector<int>> res(26, vector<int> (1510));
	for (char c = 0; c < 26; c++) {
		for (int m = 1; m <= 1500; m++) {
			for (int r = 0, l = 0, agr = 0; r < n; r++) {
				agr += s[r] != char('a' + c);

				while (l < n and agr > m) {
					agr -= s[l++] != char('a' + c);
				}

				res[c][m] = max(res[c][m], r - l + 1);
			}
		}

		for (int m = 1; m <= 1500; m++) {
			res[c][m] = max(res[c][m], res[c][m-1]);
		}
	}

	int q; cin >> q;
	while (q--) {
		int m; cin >> m;
		char c; cin >> c;

		cout << res[c-'a'][m] << endl;
	}

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
