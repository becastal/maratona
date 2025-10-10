#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	vector<vector<int>> bits(64);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 64; j++) {
			if (A[i] >> j & 1) bits[j].push_back(i);
			if (bits[j].size() >= 3) return cout << 3 << endl, 0;
		}
	}

	vector<vector<int>> G(n);
	vector<array<int, 2>> E;
	for (int j = 0; j < 64; j++) {
		if (bits[j].size() == 2) {
			int u = bits[j][0], v = bits[j][1];
			E.push_back({u, v});
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}

	auto bfs = [&](int in, int out) {
		vector<int> D(n, INF); D[in] = 0;
		queue<int> Q; Q.push(in);

		while (Q.size()) {
			int u = Q.front(); Q.pop();

			for (int v : G[u]) if (D[v] == INF and !(u == in and v == out)) {
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}
		return D[out];
	};

	int res = INF;
	for (auto [u, v] : E) {
		res = min(res, bfs(u, v));	
	}
	cout << (res == INF ? -1 : res + 1) << endl;

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
