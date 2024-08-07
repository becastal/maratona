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
	// vai ter que ter um pop[n], tot[n], e um multiset que tem tot[n] ordentado.
    vector<int> id, sz, pop, tot;
	multiset<int> pops_regioes;
    UF(int n) : id(n), sz(n, 1), pop(n), tot(n) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int i) {
        return (i == id[i] ? i : id[i] = find(id[i]));
    }

    void merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (sz[i] < sz[j]) swap(i, j);
        sz[i] += sz[j], id[j] = i;

    }
};

int main() {
    _;

    int n, m, q; 
    cin >> n >> m >> q; 

    UF dsu(n);
    for (int& i : dsu.pop) {
        cin >> i;
		dsu.pops_regioes.insert(i);
    }

    vector<pair<int, int>> arestas(m);
    for (auto& [u, v] : arestas) {
        cin >> u >> v; u--, v--;
    }

    vector<int> corta(m, 0), res;
    vector<tuple<char, int, int>> operacoes(q);
    for (auto& [qi, a, b] : operacoes) {
        cin >> qi;
        if (qi == 'K') {
            cin >> a; a--;
            corta[a] = 1;
        } else {
            cin >> a >> b; a--;
        }
    }
    reverse(operacoes.begin(), operacoes.end());

    for (int i = 0; i < m; i++) {
        if (!corta[i]) {
            dsu.merge(arestas[i].f, arestas[i].s);
        }
    }

//    for (auto [qi, a, b] : operacoes) {
//        if (qi == 'K') {
//            dsu.merge(arestas[a].f, arestas[a].s);
//        } else {
//            dsu.update_size(a, b);    
//        }
//        res.push_back(dsu.maior);
//    }
//    reverse(res.begin(), res.end());
//
    for (int i : res) {
        cout << i << ' ';
    }
    cout << endl;
    
    return 0;
}

