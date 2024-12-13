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

int main()
{
    _;

	int n, m; cin >> n >> m;
	int res = 0;
	vector mp(n, vector<char>(m));
	vector d(n, vector<int>(m, 0));

	for (auto& l : mp) for (auto& c : l) cin >> c;

	deque<ii> q;
	q.emplace_back(0, 0);
	d[0][0] = 1;

	auto valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and mp[i][j] != '.';
	};

	vector<ii> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (q.size()) {
		auto [ui, uj] = q.front();
		q.pop_front();
		res = max(res, d[ui][uj]);

		for (ii mov : movs) {
			int vi = ui + mov.f, vj = uj + mov.s;

			if (valido(vi, vj) and d[vi][vj] == 0) {
				if (mp[vi][vj] == mp[ui][uj]) {
					d[vi][vj] = d[ui][uj];
					q.emplace_front(vi, vj);
				} else {
					d[vi][vj] = d[ui][uj] + 1;
					q.emplace_back(vi, vj);
				}
			}
		}
	}

	cout << res << endl;

    return(0);
}
