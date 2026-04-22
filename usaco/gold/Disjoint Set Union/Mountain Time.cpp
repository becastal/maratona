#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dir = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

struct Dsu {
    int n, m;
    vector<int> id, sz, mx, mn, vivo;

    Dsu(int n_, int m_) : n(n_), m(m_), id(n * m), sz(n * m, 1),
                          mx(n * m), mn(n * m), vivo(n * m, 0) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int u) {
        return u == id[u] ? u : id[u] = find(id[u]);
    }

    int merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        id[v] = u;
        sz[u] += sz[v];
        mx[u] = max(mx[u], mx[v]);
        mn[u] = min(mn[u], mn[v]);
        return 1;
    }

    void add(int ui, int uj, int val) {
        int u = ui * m + uj;
        vivo[u] = 1;
        mx[u] = mn[u] = val;

        for (auto [di, dj] : Dir) {
            int vi = ui + di, vj = uj + dj;
            if (vi < 0 || vj < 0 || vi >= n || vj >= m) continue;
            int v = vi * m + vj;
            if (vivo[v]) merge(u, v);
        }
    }

    int maior(int ui, int uj) {
        return mx[find(ui * m + uj)];
    }
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> A(n, vector<int>(m));
	vector<int> B(n * m);
	
	for (int i = 0, p = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int& v = A[i][j]; cin >> v;
			B[p++] = v;
		}
	}

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	int mm = (int)B.size();

	vector<vector<array<int, 2>>> Ocor(mm);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int p = lower_bound(all(B), A[i][j]) - B.begin();
			Ocor[p].push_back({i, j});
		}
	}

	vector<vector<int>> L(n, vector<int>(m, 0)), 
						R(n, vector<int>(m, mm - 1)), 
						Res(n, vector<int>(m, -1));
	vector<vector<array<int, 2>>> Mids(mm);

	for (int rep = 0, lim = __lg(n * m) + 2; rep < lim; rep++) {
		Dsu dsu(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int l = L[i][j], r = R[i][j];
				if (l <= r) {
					int mid = l + (r - l) / 2;
					Mids[mid].push_back({i, j});
				}
			}
		}


		for (int mid = mm-1; mid >= 0; mid--) { 
			for (auto [ui, uj] : Ocor[mid]) {
				dsu.add(ui, uj, A[ui][uj]);	
			}

			for (auto [ui, uj] : Mids[mid]) {
				if (dsu.maior(ui, uj) > A[ui][uj]) {
					L[ui][uj] = mid + 1;
					Res[ui][uj] = mid;
				} else {
					R[ui][uj] = mid - 1;	
				}
			}
			Mids[mid].clear();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { 
			if (Res[i][j] == -1) {
				cout << A[i][j] << " \n"[j==m-1];
			} else {
				cout << max(0LL, A[i][j] - B[Res[i][j]]) << " \n"[j==m-1];
			}
		}
	}

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

