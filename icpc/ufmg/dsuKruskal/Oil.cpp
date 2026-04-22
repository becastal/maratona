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
	int cont;
	vector<int> id, sz;
	DSU(int n) : id(n), cont(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return 0;
		id[j] = i;
		cont--;
		return 1;
	}
};

int main()
{
    _;

	int n, m, id_ = 0; cin >> n >> m;
	ll s; cin >> s;
	vector<tuple<ll, int, int, int>> ed(m);
	for (auto& [w, u, v, id] : ed) {
		cin >> u >> v >> w; u--, v--;
		id = ++id_;
	}
	sort(ed.rbegin(), ed.rend());
	
	DSU dsu(n);
	vector<int> ruim(m, 0), res;
	for (int i = 0; i < m; i++) {
		auto [w, u, v, id] = ed[i];
		ruim[i] = dsu.merge(u, v);
		if (dsu.cont == 1) break;
	}

	for (int i = m-1; i >= 0; i--) {
		auto [w, u, v, id] = ed[i];
		if (s < w) break;
		if (ruim[i]) continue;

		s -= w;
		res.push_back(id);
	}
		
	cout << res.size() << endl;
	for (int i : res ) cout << i << ' '; cout << endl;
    
    return(0);
}

