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
	int n, xa, ya, xb, yb;
	cin >> n >> xa >> ya >> xb >> yb;

	vector<pair<int, int>> a(n);
	for (auto& [x, y] : a) cin >> x >> y;

	a.insert(a.begin(), pair<int, int>(xa, ya));
	a.insert(a.end(), pair<int, int(xb, yb));

	n += 2;
	map<int, vector<int>> gx, gy;
	for (int i = 0; i < n; i++) {
		auto [x, y] = a[i];

		gx[x].push_back(i);
		gy[y].push_back(i);
	}

	auto bfs = [&]() {
		vector<int> d(n, INF); d[0] = 0;
		queue<int> q; q.emplace(0);
		
		while (q.size()) {
			int u = q.front(); q.pop();
			auto [xu, yu] = a[u];

			for (int v : gx
		}

		return d.back() == INF ? -1 : d.back();
	};

	cout << bfs() << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
