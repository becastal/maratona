#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n, cc;
	vector<int> id, sz;

	Dsu(int n_) : n(n_), cc(n), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int u) {
		return u == id[u] ? u : id[u] = find(id[u]);
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);		
		sz[u] += sz[v];
		id[v] = id[u];
		cc--;
		return 1;
	}
};

int solve() {
	int n; cin >> n;
	
	vector<array<int, 2>> A(n);
	vector<array<int, 3>> E;
	
	map<int, vector<int>> Y;
	for (int i = 0; i < n; i++) {
		auto& [x, y] = A[i];
		cin >> x >> y;	
		Y[y].push_back(i);
	}

	auto dist = [&](int i, int j) {
		auto [xi, yi] = A[i];
		auto [xj, yj] = A[j];
		return (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
	};

	vector<vector<int>> Yv;
	for (auto& [yl, V] : Y) {
		sort(all(V), [&](int i, int j) {
			return A[i][0] < A[j][0];
		});
		Yv.push_back(V);
	}

	for (int y1 = 0; y1 < (int)Yv.size(); y1++) {
		auto& V = Yv[y1];
		for (int i = 1; i < (int)V.size(); i++) {
			int u = V[i-1], v = V[i];
			E.push_back({dist(u, v), u, v});
		}

		for (int y2 = y1 + 1; y2 < (int)Yv.size(); y2++) {
			auto& V_ = Yv[y2];

			for (int u : V) {
				int l = 0, r = (int)V_.size()-1, pos = -1;
				while (l <= r) {
					int mid = l + (r - l) / 2;

					if (A[V_[mid]][0] >= A[u][0]) {
						r = mid - 1;
						pos = mid;
					} else {
						l = mid + 1;
					}
				}

				if (pos != -1) {
					E.push_back({dist(u, V_[pos]), u, V_[pos]});
				}
				if (pos > 0) {
					E.push_back({dist(u, V_[pos - 1]), u, V_[pos - 1]});
				}
				if (pos == -1 and !V_.empty()) {
					E.push_back({dist(u, V_.back()), u, V_.back()});
				}
			}
		}
	}
	//for (int i = 0; i < n; i++) { 
	//	for (int j = i+1; j < n; j++) {
	//		E.push_back({dist(i, j), i, j});
	//	}
	//}

	sort(all(E));
	Dsu dsu(n);
	int res = 0;
	for (auto& [w, u, v] : E) {
		if (dsu.merge(u, v)) {
			res += w;
			// printf("{(%lld, %lld), (%lld, %lld): %lld}\n", A[u][0], A[u][1], A[v][0], A[v][1], w);
		}
		res += dsu.merge(u, v) * w;
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

