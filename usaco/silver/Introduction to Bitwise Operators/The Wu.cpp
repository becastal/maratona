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

int main()
{
    _;

	int n, m, q; cin >> n >> m >> q;

	vector<int> v(n), cont((1 << n), 0);
	for (int& i : v) cin >> i;

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		int x = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') x |= (1 << j);
		}
		cont[x]++;
	}

	vector<vector<int>> res((1 << n), vector<int>(110));

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			int vi = 0;
			for (int ii = 0; ii < n; ii++) {
				if ((i >> ii & 1) == (j >> ii & 1)) {
					vi += v[ii];
				}
			}

			if (vi <= 100) res[i][vi] += cont[j];
		}
	}

	for (auto& v_ : res) {
		for (int i = 1; i < 110; i++) {
			v_[i] += v_[i-1];	
		}
	}

	while (q--) {
		string s; cin >> s;
		int k; cin >> k;

		int x = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') x |= (1 << i);
		}

		cout << res[x][k] << endl;
	}
    
    return(0);
}
