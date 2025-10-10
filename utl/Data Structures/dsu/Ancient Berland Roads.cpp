#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<ll> id, sz, cont;

	map<ll, int> F;
	Dsu(int n, vector<ll>& A) : id(n), sz(n, 1), cont(A) {
		iota(id.begin(), id.end(), 0);
		for (int i = 0; i < n; i++) {
			F[sz[i] = cont[i]]++;
		}
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		if (--F[sz[j]] == 0) F.erase(sz[j]);
		if (--F[sz[i]] == 0) F.erase(sz[i]);
		sz[i] += sz[j], id[j] = i;
		F[sz[i]]++;
	}

	void update(int i, int x) {
		int j = find(i);	

		int d = x - cont[i];
		if (--F[sz[j]] == 0) F.erase(sz[j]);
		F[sz[j] += d]++;

		cont[i] = x;
	}
};

int solve() {
	int n, m, q; cin >> n >> m >> q;

	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	vector<array<int, 2>> E(m);
	for (auto& [u, v] : E) {
		cin >> u >> v; u--, v--;
	}

	vector<array<int, 3>> Q(q);
	
	vector<int> ruim(m, 0);
	for (int i = 0; i < q; i++) {
		char tp; cin >> tp;

		if (tp == 'D') {
			int j; cin >> j; j--;
			Q[i] = {0, j, -1};
			ruim[j] = 1;
		} else {
			int j, x; cin >> j >> x; j--;
			Q[i] = {1, j, int(A[j])};
			A[j] = x;
		}
	}

	Dsu dsu(n, A);
	for (int i = 0; i < m; i++) if (!ruim[i]) {
		dsu.merge(E[i][0], E[i][1]);
	}

	vector<ll> R;
	reverse(all(Q));
	for (auto [tp, a, b] : Q) {
		R.push_back(dsu.F.rbegin()->first);
		if (tp == 0) {
			dsu.merge(E[a][0], E[a][1]);
		} else {
			dsu.update(a, b);
		}
	}

	reverse(all(R));
	for (ll i : R) {
		cout << i << endl;
	}

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

