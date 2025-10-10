#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct DSU {
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
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

int solve() {
	int n, q; cin >> n >> q;
	vector<array<int, 3>> E(n-1);
	for (auto& [w, u, v] : E) {
		cin >> u >> v >> w; u--, v--;
	}
	int cont = 0;
	vector<array<int, 3>> Q(q);
	for (auto& [ki, ui, id] : Q) {
		cin >> ki >> ui; ui--;
		id = cont++;
	}
	sort(rall(E));
	sort(rall(Q));

	DSU dsu(n);
	vector<int> res(q);
	for (int i = 0, j = 0; i < q; i++) {
		auto [ki, ui, id] = Q[i];

		while (j < n-1 and E[j][0] >= ki) {
			dsu.merge(E[j][1], E[j][2]);	
			j++;
		}
		res[id] = dsu.sz[dsu.find(ui)] - 1;
	}
	for (int i : res) cout << i << endl;

	return(0);
}
void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("mootube");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

