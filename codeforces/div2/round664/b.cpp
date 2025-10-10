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

	int n, m; cin >> n >> m;
	int ini, inj; cin >> ini >> inj;

	vector<pair<int, int>> res = {
		{ini, inj},
		{1, inj},
		{1, 1},
	};
	set<pair<int, int>> vis(res.begin(), res.end());
	
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= m; j++) {
				if (!vis.count({i, j})) {
					res.emplace_back(i, j);
					vis.emplace(i, j);
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				if (!vis.count({i, j})) {
					res.emplace_back(i, j);
					vis.emplace(i, j);
				}
			}
		}
	}
    
	for (auto [a, b] : res) {
		cout << a << ' ' << b << endl;
	}

    return(0);
}
