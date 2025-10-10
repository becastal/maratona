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
	setIO("countcross");

	int n, k, r; cin >> n >> k >> r;
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	set<tuple<int, int, int, int>> ruim;
	for (int i = 0, ui, uj, vi, vj; i < r; i++) {
		cin >> ui >> uj >> vi >> vj; ui--, uj--, vi--, vj--;
		ruim.emplace(ui, uj, vi, vj);
		ruim.emplace(vi, vj, ui, uj);
	}

	vector<pair<int, int>> a(k);

	for (auto& [i, j] : a) {
		cin >> i >> j; i--, j--;
	}

	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < n; };
	auto bfs = [&](int si, int sj) {
		vector<vector<int>> d(n, vector<int>(n, INF)); d[si][sj] = 0;
		deque<pair<int, int>> q; q.emplace_back(si, sj);

		while (q.size()) {
			auto [ui, uj] = q.front(); q.pop_front();

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj, w = ruim.count(make_tuple(ui, uj, vi, vj));
				if (!valido(vi, vj)) continue;

				if (d[vi][vj] > d[ui][uj] + w) {
					d[vi][vj] = d[ui][uj] + w;

					if (w) q.emplace_back(vi, vj);
					else q.emplace_front(vi, vj);
				}
			}
		}

		return d;
	};

	int res = 0;
	for (auto& [ui, uj] : a) {
		auto d = bfs(ui, uj);

//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << d[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;

		for (auto [vi, vj] : a) {
			res += d[vi][vj] >= 1;
		}
	}

	cout << res / 2 << endl;

    return(0);
}
