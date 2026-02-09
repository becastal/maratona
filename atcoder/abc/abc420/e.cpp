#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<int> id, sz, preto;
	Dsu(int n) : id(n), sz(n, 1), preto(n, 0) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], preto[i] += preto[j], id[j] = i;
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> cor(n, 0);
	Dsu dsu(n);

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int u, v; cin >> u >> v; u--, v--;
			dsu.merge(u, v);
		} else if (tp == 2) {
			int u; cin >> u; u--;
			if (cor[u] ^= 1) {
				dsu.preto[dsu.find(u)]++;	
			} else {
				dsu.preto[dsu.find(u)]--;	
			}
		} else if (tp == 3) {
			int u; cin >> u; u--;
			cout << (dsu.preto[dsu.find(u)] ? "Yes" : "No") << endl;
		}
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

