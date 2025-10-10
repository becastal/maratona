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

const int MOD = 1e9+7;
#define MODULAR false
template<typename T> struct matrix : vector<vector<T>> {
	int n, m;

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}

	matrix(int n_, int m_, bool ident = false, ll val = 0) :
			vector<vector<T>>(n_, vector<T>(m_, val)), n(n_), m(m_) {
		if (ident) {
			assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 0;
		}
	}
	matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
		n(c.size()), m(c[0].size()) {}
	matrix(const initializer_list<initializer_list<T>>& c) {
		vector<vector<T>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}

	matrix<T> operator*(matrix<T>& r) {
		matrix<T> res(n, n, false, LINF);			

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if ((*this)[a][b] == LINF) continue;
				for (int c = 0; c < n; c++) {
					res[a][c] = min(res[a][c], (*this)[a][b] + r[b][c]);
				}
			}
		}

		return res;
	}
	matrix<T> operator^(ll e){
		matrix<T> M(n, n, false, LINF), at = *this;
		for (int i = 0; i < n; i++) M[i][i] = 0;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
	void apply_transform(matrix M, ll e){
		auto& v = *this;
		while (e) {
			if (e&1) v = M*v;
			e >>= 1;
			M = M*M;
		}
	}
};

int solve() {
	int n, m, k; cin >> n >> m >> k;

	matrix<ll> M(n, n, false, LINF);
	for (int i = 0, u, v, c; i < m; i++) {
		cin >> u >> v >> c; u--, v--;
		M[u][v] = min(M[u][v], (ll)c);
	}

	M = M ^ k;
	if (M[0][n-1] == LINF) return cout << -1 << endl, 0;
	cout << M[0][n-1] << endl;


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
