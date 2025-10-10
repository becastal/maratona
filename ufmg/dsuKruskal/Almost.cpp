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

struct DSU {
	vector<ll> id, sz, sm;
	DSU(int n) : id(n), sz(n, 1), sm(n) {
		iota(id.begin(), id.end(), 0);
		iota(sm.begin(), sm.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j];
		sm[i] += sm[j];
		id[j] = i;
	}
};

void solve(int n, int m) {
	DSU dsu(n + m + 1);
	vector<int> pos(n + m + 1);
	for (int i = 1; i <= n; i++) {
		pos[i] = i;
	}
	int cont = n+1;

	while (m--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int p, q; cin >> p >> q;
			p = dsu.find(pos[p]), q = dsu.find(pos[q]);
			dsu.merge(p, q);
		} else if (tp == 2) {
			int p, q; cin >> p >> q;
			int a = dsu.find(pos[p]), b = dsu.find(pos[q]);

			if(a == b) continue;
			dsu.sz[a]--, dsu.sm[a] -= p;
			
			pos[p] = cont;
			dsu.id[cont] = cont;
			dsu.sz[cont] = 1;
			dsu.sm[cont] = p;
			cont++;
			
			dsu.merge(b, pos[p]);
	} else if (tp == 3) {
			int p; cin >> p;
			p = dsu.find(pos[p]);
			cout << dsu.sz[p] << ' ' << dsu.sm[p] << endl;
		}
	}
}

int main()
{
    _;

	int n, m; 
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}
