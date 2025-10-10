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
	vector<vector<int>> V;
	DSU(int n) : id(n), sz(n, 1), V(n) {
		iota(id.begin(), id.end(), 0);
		for (int i = 0; i < n; i++) V[i].push_back(i);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		for (int k : V[j]) V[i].push_back(k);
		V[j].clear();
	}
};

int solve() {
	int n; cin >> n;

	DSU dsu(n);
	for (int i = 0, a, b; i < n-1; i++) {
		cin >> a >> b; a--, b--;
		dsu.merge(a, b);
	}

	for (auto v : dsu.V) {
		if (v.size()) for (int i : v) cout << i+1 << ' ';
	}
	cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
