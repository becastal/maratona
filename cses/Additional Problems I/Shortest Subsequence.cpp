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

map<char, int> val = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, };
map<int, char> val_ = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}, };

int solve() {
	string s; cin >> s;
	int n = s.size();

	vector<vector<int>> prox(n+1, vector<int>(4, n));
	for (int i = n-1; i >= 0; i--) {
		prox[i] = prox[i+1];
		prox[i][val[s[i]]] = i;
	}

	string res = "";
	for (int u = 0; u < n; ) {
		int mx = -1, pos = -1;
		for (int i = 0; i < 4; i++) {
			if (mx < prox[u][i]) {
				mx = prox[u][i];
				pos = i;
			}
		}

		res.push_back(val_[pos]);
		if (mx == n-1) res.push_back('A');
		u = mx + 1;
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
