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

int main()
{
    _;

	int n, k; cin >> n >> k;
	DSU dsu(n);

	for (int i = 0; i < k; i++) {
		char qi; cin >> qi;
		int u, v; cin >> u >> v; u--, v--; 

		if (qi == 'F') {
			dsu.merge(u, v);	
		} else {
			cout << (dsu.find(u) == dsu.find(v) ? 'S' : 'N') << endl;	
		}
	}
    
    return(0);
}
