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
typedef pair<int, int> ii;

void solve() {
	char cai, caj, cbi, cbj;
	cin >> cai >> caj >> cbi >> cbj;

	int ai = (int)cai - 'a', aj = (int)caj - '1';
	int bi = (int)cbi - 'a', bj = (int)cbj - '1';
	swap(ai, aj), swap(bi, bj);

	vector<ii> movs = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};
	vector<vector<int>> d(8, vector<int>(8, -1));

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < 8 and j < 8 and d[i][j] == -1;
	};

	auto bfs = [&]() {
		queue<ii> q; q.emplace(ii(ai, aj));
		d[ai][aj] = 0;

		while (!q.empty()) {
			auto [ui, uj] = q.front(); q.pop();

			for (auto mov : movs) {
				int vi = ui + mov.f, vj = uj + mov.s;
				if (!valido(vi, vj)) continue;

				q.emplace(vi, vj);
				d[vi][vj] = d[ui][uj] + 1;
			}
		}
	};
	bfs();

	cout << d[bi][bj] << endl;
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
