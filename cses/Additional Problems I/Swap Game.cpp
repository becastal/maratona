#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int in = 0, out = 123456789;
	for (int i = 0, x; i < 9; i++) {
		cin >> x;
		in = 10 * in + x;
	}

	vector<int> pot = {1};
	for (int i = 0; i < 10; i++) {
		pot.push_back(pot.back() * 10);
	}
	queue<int> q; q.emplace(in);
	unordered_map<int, int> d; d[in] = 0;

	auto valido = [](int i, int j) { return i >= 0 and j >= 0 and i < 3 and j < 3; };
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	while (q.size()) {
		int u = q.front(); q.pop();
		if (u == out) return cout << d[u] << endl, 0;

		for (int p = 0; p < 9; p++) {
			int ui = p / 3, uj = p % 3;
			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;	
				if (!valido(vi, vj)) continue;

				int ii = pot[ui * 3 + uj], jj = pot[vi * 3 + vj];
				int pi = u / ii % 10, pj = u / jj % 10;
				int v = u + (pj - pi) * ii + (pi - pj) * jj;

				if (d.count(v)) continue;
				d[v] = d[u] + 1;
				q.emplace(v);
			}

		}
	}
	cout << d[out] << endl;

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
