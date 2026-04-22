#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	vector<int> id, sz, bip, c;
	vector<array<int, 2>> C;
	int total;

	Dsu(int n) : id(n), sz(n, 1), bip(n, 1), c(n), C(n, {1, 0}), total(0) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int a) { return a == id[a] ? a : find(id[a]); }
	int color(int a) { return a == id[a] ? c[a] : c[a] ^ color(id[a]); }
	int custo(int a) { return min(C[a][0], C[a][1]); }

	int unite(int a, int b) {
		bool change = color(a) == color(b);
		a = find(a), b = find(b);
		if (a == b) {
			if (change) {
				bip[a] = 0;
				return 0;
			}
			return 1;
		}
		if (sz[a] < sz[b]) swap(a, b);

        total -= custo(a);
        total -= custo(b);

        id[b] = a;
        c[b] = change;
        sz[a] += sz[b];

        if (!change) {
            C[a][0] += C[b][0];
            C[a][1] += C[b][1];
        } else {
            C[a][0] += C[b][1];
            C[a][1] += C[b][0];
        }
        total += custo(a);

		return 1;
	}
};

int solve() {
	int n, q; cin >> n >> q;

	Dsu dsu(n);
	for (int i = 0, u, v, ruim = 0; i < q; i++) {
		if (ruim) {
			cout << -1 << endl;
			continue;
		}

		cin >> u >> v; u--, v--;

		ruim |= !dsu.unite(u, v);
		
		if (ruim) cout << -1 << endl;
		else {
			cout << dsu.total << endl;
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

