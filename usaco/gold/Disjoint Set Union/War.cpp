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

	Dsu(int n) : id(n), sz(n, 1), bip(n, 1), c(n) { 
		iota(id.begin(), id.end(), 0); 
	}

	int find(int a) { return a == id[a] ? a : find(id[a]); }
	int color(int a) { return a == id[a] ? c[a] : c[a] ^ color(id[a]); }

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
		if (change) c[b] = 1;
		sz[a] += sz[b], id[b] = a, bip[a] &= bip[b];
		return 2;
	}

	int areFriends(int a, int b) {
		return find(a) == find(b) and color(a) == color(b);
	}

	int areEnemies(int a, int b) {
		return find(a) == find(b) and color(a) != color(b);
	}
};

int solve() {
	int n, op1 = 0; cin >> n;	

	vector<array<int, 3>> Op;
	for (int c, x, y; cin >> c >> x >> y and c;) {
		op1 += (c == 1);
		Op.push_back({c, x, y});
	}

	Dsu dsu(n + op1);
	for (int i = 0, p = n; i < (int)Op.size(); i++) { 
		auto [c, x, y] = Op[i];

		if (c == 1) {
			if (!dsu.unite(x, p) or !dsu.unite(p, y)) {
				cout << -1 << endl;
			}
			p++;
		} else if (c == 2) {
			if (!dsu.unite(x, y)) {
				cout << -1 << endl;
			}
		} else if (c == 3) {
			cout << dsu.areFriends(x, y) << endl;
		} else if (c == 4) {
			cout << dsu.areEnemies(x, y) << endl;
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
