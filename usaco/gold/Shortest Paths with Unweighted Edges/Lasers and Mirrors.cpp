#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

vector<array<int, 2>> Dir = {
	{-1, 0},
	{+1, 0},
	{0, +1},
	{0, -1},
};

int solve() {
	int n; cin >> n; n += 2;
	vector<array<int, 2>> A(n);	

	vector<vector<int>> Viz(n, vector<int>(4, -1));
	map<int, vector<int>> X, Y;

	for (int i = 0; i < n; i++) {
		auto& [x, y] = A[i];
		cin >> x >> y;
		X[x].push_back(i);
		Y[y].push_back(i);
	}

	for (auto& [y, V] : Y) {
		sort(all(V), [&](int a, int b) {
			return A[a][0] < A[b][0];
		});

		for (int i = 1; i < (int)V.size(); i++) {
			int u = V[i], v = V[i-1];
			Viz[u][0] = v;
		}
		
		for (int i = 0; i + 1 < (int)V.size(); i++) {
			int u = V[i], v = V[i+1];
			Viz[u][1] = v;
		}
	}

	for (auto& [x, V] : X) {
		sort(all(V), [&](int a, int b) {
			return A[a][1] < A[b][1];
		});

		for (int i = 0; i + 1 < (int)V.size(); i++) {
			int u = V[i], v = V[i+1];
			Viz[u][2] = v;
		}

		for (int i = 1; i < (int)V.size(); i++) {
			int u = V[i], v = V[i-1];
			Viz[u][3] = v;
		}
	}
	
	deque<array<int, 2>> Q;
	vector<vector<int>> D(n, vector<int>(4, LLONG_MAX));

	for (int d = 0; d < 4; d++) {
		Q.push_front({0, d});
		D[0][d] = 0;
	}

	while (Q.size()) {
		auto [u, diru] = Q.front(); Q.pop_front();
		// cout << u << ", " << diru << endl;
		
		for (int dirv = 0; dirv < 4; dirv++) {
			if (diru == dirv) {
				int v = Viz[u][diru];
				if (v != -1 and D[v][dirv] > D[u][diru]) {
					D[v][dirv] = D[u][diru];
					Q.push_front({v, dirv});
				}
			} else if (diru / 2 == dirv / 2) {
				continue;	
			} else {
				int v = Viz[u][dirv];
				if (v != -1 and D[v][dirv] > D[u][diru] + 1) {
					D[v][dirv] = D[u][diru] + 1;
					Q.push_back({v, dirv});
				}
			}
		}
	}

	int res = LLONG_MAX;
	for (int d = 0; d < 4; d++) {
		res = min(res, D[1][d]);	
	}
	if (res == LLONG_MAX) res = -1;
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main() {
    _;
	setIO("lasers");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

