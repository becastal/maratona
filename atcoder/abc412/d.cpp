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
	int n, m; cin >> n >> m;
	vector<vector<int>> M(n, vector<int>(n, 0));
	vector<pair<int, int>> E(m);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		M[u][v] = M[v][u] = 1;
		E[i] = minmax(u, v);
	}

	int res = INF;
	vector<int> P(n);
	iota(all(P), 0);
	do {
		int add = 0, rem = 0;
		vector<vector<int>> M_(n, vector<int>(n, 0));
		for (int u = 0; u < n; u++) {
			int v = (u-1+n) % n;
			if (!M[P[u]][P[v]]) add++;
			M_[P[u]][P[v]] = M_[P[v]][P[u]] = 1;
		}

		for (auto [u, v] : E) {
			if (!M_[u][v]) rem++;
		}

		// 6: (3, 3)
		// 7: (3, 4), (4, 3);
		// 8: (3, 5), (4, 4), (5, 3);

		vector<int> H;
		if (n >= 6) H.push_back(3);
		if (n >= 7) H.push_back(4);
		if (n >= 8) H.push_back(5);

		for (int nn : H) {
			int add_ = 0, rem_ = 0;
			vector<vector<int>> A(n, vector<int>(n, 0));
			vector<int> B(P.begin(), P.begin() + nn);
			vector<int> C(P.begin() + nn, P.end());
			
			for (auto V : {B, C}) {
				int nnn = V.size();
				for (int u = 0; u < nnn; u++) {
					int v = (u+1) % nnn;
					if (!M[V[u]][V[v]]) add_++;
					A[V[u]][V[v]] = A[V[v]][V[u]] = 1;
				}
			}

			for (auto [u, v] : E) {
				if (!A[u][v]) rem_++;
			}
			res = min(res, add_ + rem_);
		}

		res = min(res, add + rem);
	} while (next_permutation(all(P)));
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
