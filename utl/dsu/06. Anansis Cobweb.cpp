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

struct UF {
	int c;
	vector<int> id, sz;
	UF(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
		c = n;
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		c--;
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	UF dsu(n);

	vector<pair<int, int>> arestas(m);
	for (auto& [u, v] : arestas) {
		cin >> u >> v; u--, v--;
	}

	int q; cin >> q;	
	vector<int> corta(m, 0), ordem(q), res;
	for (auto& i : ordem) {
		cin >> i; i--;
		corta[i] = 1;	
	}

	for (int i = 0; i < m; i++) {
		if (!corta[i]) {
			dsu.merge(arestas[i].f, arestas[i].s);
		}
	}
	reverse(ordem.begin(), ordem.end());
	
	for (int i : ordem) {
		res.push_back(dsu.c);
		dsu.merge(arestas[i].f, arestas[i].s);
	}
	reverse(res.begin(), res.end());

	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
    
    return(0);
}
