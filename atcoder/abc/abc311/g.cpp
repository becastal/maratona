#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	int n;
	ll mx;
	vector<ll> id, sz, s, vivo;
	Dsu(int n_, vector<ll>& B) : n(n_), mx(0), id(n), sz(n, 1), s(B), vivo(n, 0) {
		iota(all(id), 0);
	};

	int find(int u) {
		return (u == id[u] ? u : id[u] = find(id[u]));
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		id[v] = u;
		sz[u] += sz[v];
		s[u] += s[v];
		mx = max(mx, s[u]);
		return 1;
	}

	void merga(int u) {
		mx = max(mx, s[u]);
		vivo[u] = 1;
		for (int i : {-1, +1}) {
			if (u + i >= 0 and u + i < n and vivo[u + i]) {
				merge(u, u + i);
			}
		}
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> M(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}

	auto solve = [n](vector<ll>& A, vector<ll>& B) {
		vector<int> P(n);
		iota(all(P), 0);
		sort(all(P), [&A](int i, int j) { return A[i] > A[j]; });

		//cerr << "A: "; for (int i : A) cerr << i << ' '; cerr << endl;
		//cerr << "B: "; for (int i : B) cerr << i << ' '; cerr << endl;

		ll res = 0;
		Dsu dsu(n, B);
		for (int l = 0, r; l < n; l = r) {
			r = l + 1;
			dsu.merga(P[l]);
			while (r < n and A[P[l]] == A[P[r]]) {
				dsu.merga(P[r++]);
			}
			res = max(res, 1LL * dsu.mx * A[P[l]]);

		//	for (int i = 0; i < n; i++) {
		//		cerr << dsu.vivo[i] << " \n"[i==n-1];
		//	}
		//	cerr << "mx: " << dsu.mx << endl;
		//	cerr << "A[P[l]]: " << A[P[l]] << endl;
		}
		return res;
	};

	ll res = 0;
	for (int j = 0; j < m; j++) {
		vector<ll> A(n, LLONG_MAX), B(n, 0);
		for (int jj = j; jj < m; jj++) {
			for (int i = 0; i < n; i++) {
				A[i] = min(A[i], ll(M[i][jj]));
				B[i] += M[i][jj];
			}
			res = max(res, solve(A, B));
		}
	}
	cout << res << endl;

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

