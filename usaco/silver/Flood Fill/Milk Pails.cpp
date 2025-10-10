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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("pails");

	int x, y, k, m; cin >> x >> y >> k >> m;

	vector<vector<int>> d(x + 1, vector<int>(y + 1, INF)); d[0][0] = 0;
	queue<pair<int, int>> q; q.emplace(0, 0);

	while (q.size()) {
		auto [ui, uj] = q.front(); q.pop();

		int di = min(uj, x - ui), dj = min(ui, y - uj);
		vector<pair<int, int>> movs = {
			{0, uj},
			{ui, 0},
			{x, uj},
			{ui, y},
			{ui + di, uj - di},
			{ui - dj, uj + dj}
		};

		for (auto [vi, vj] : movs) {
			if (d[vi][vj] != INF) continue;
			d[vi][vj] = d[ui][uj] + 1;
			q.emplace(vi, vj);
		}
	}

	int res = INF;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (d[i][j] <= k) {
				res = min(res, abs(m - (i + j)));
			}
		}
	}
	cout << res << endl;

    return(0);
}
