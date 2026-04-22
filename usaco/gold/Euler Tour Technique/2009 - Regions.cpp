#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Bit {
	int n;
	vector<int> F;

	Bit(int n_) : n(n_), F(n+1) {};
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) {
			F[i] += x;
		}
	}

	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res += F[i];
		}
		return res;
	}
};

int solve() {
	int n, r, q; cin >> n >> r >> q;
	vector<int> Pai(n, -1), Cor(n);
	vector<vector<int>> G(n), OcorU(r), Ocor(r);

	for (int i = 0; i < n; i++) {
		if (i) {
			cin >> Pai[i]; Pai[i]--;
			cin >> Cor[i]; Cor[i]--;
			G[Pai[i]].push_back(i);
		} else {
			cin >> Cor[i]; Cor[i]--;
		}
		OcorU[Cor[i]].push_back(i);
	}

	int t = 0;
	vector<int> L(n), R(n);
	function<void(int)> dfs = [&](int u) {
		Ocor[Cor[u]].push_back(L[u] = t++);
		for (int v : G[u]) {
			dfs(v);
		}
		R[u] = t;
	};
	dfs(0);

	for (int r1 = 0; r1 < r; r1++) {
		sort(all(Ocor[r1]));
	}

	Bit bit(n);
	vector<vector<int>> Res;
	vector<int> Id(r);

	function<void(int, int, int)> dfs2 = [&](int u, int cont_cor, int cor_pai) {
		cont_cor += (Cor[u] == cor_pai);
		Res.back()[Cor[u]] += cont_cor;
		for (int v : G[u]) {
			dfs2(v, cont_cor, cor_pai);
		}
	};

	int RAIZ = ceil(sqrt(n));
	for (int r1 = 0, id = 0; r1 < r; r1++) if ((int)Ocor[r1].size() >= RAIZ) {
		Id[r1] = id++;
		Res.push_back(vector<int>(r));
		dfs2(0, 0, r1);
	}

	for (int i = 0, r1, r2; i < q; i++) {
		cin >> r1 >> r2; r1--, r2--;

		if ((int)Ocor[r1].size() >= RAIZ) {
			cout << Res[Id[r1]][r2] << endl;
		} else {
			int res = 0;
			for (int u : OcorU[r1]) {
				res += lower_bound(all(Ocor[r2]), R[u]) - lower_bound(all(Ocor[r2]), L[u]);
			}
			cout << res << endl;
		}
		cout << flush;
	}

	return(0);
}

signed main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

