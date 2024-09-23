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
	vector<int> id, sz;
	vector<vector<int>> vert;
	int n;
	DSU(int ni) : id(ni), sz(ni, 1), vert(ni) {
		n = ni;
		iota(id.begin(), id.end(), 0);
		for (int i = 0; i < n; i++) {
			vert[i].push_back(i);	
		}
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	int query(int v, int k) {
		v = find(v);
		if (sz[v] < k) return -1;
		return vert[v][sz[v] - k] + 1;
	}

	void join(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		
		vector<int> temp;
		merge(vert[i].begin(), vert[i].end(), vert[j].begin(), vert[j].end(), back_inserter(temp));
		vert[i] = move(temp);
		vert[j].clear();
	}
};

int main()
{
    _;

	// alguma variacao maneira de dsu
	// quando dar merge, fazer um push_back num vector mas igual merge sort segtree.
	// dai em cada query buscar o pai e achar o k-esimo valor de tras pra frente no pai.
	// a malandragem eh que eu so preciso guardar os k primeiros valores no merge porque k <= 10;
	int n, q; cin >> n >> q;
	DSU dsu(n);

	for (int i = 0, tp; i < q; i++) {
		cin >> tp;
		if (tp == 1) {
			int u, v; cin >> u >> v; u--, v--;
			dsu.join(u, v);
		} else {
			int v, k; cin >> v >> k; v--;
			cout << dsu.query(v, k) << endl;
		}
	}
    
    return(0);
}
