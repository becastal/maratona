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
	vector<int> id, sz;
	UF(int n) : id(n), sz(n, 1) {
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

int main()
{
    _;

	int n, m, k; cin >> n >> m >> k;
	UF dsu(n);
	
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
	}

	vector<tuple<string, int, int>> q(k);
	for (auto& [qi, u, v] : q) {
		cin >> qi >> u >> v; u--, v--;
	}
	reverse(q.begin(), q.end());
	
	vector<string> res;
	for (auto [qi, u, v] : q) {
		if (qi == "ask") {
			res.push_back(dsu.find(u) == dsu.find(v) ? "YES" : "NO");
		} else {
			dsu.merge(u, v);
		}
	}
	reverse(res.begin(), res.end());
	
	for (auto ri : res)
		cout << ri << endl;
    
    return(0);
}
