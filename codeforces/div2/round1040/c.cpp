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
	int n, m = 1; cin >> n;
	vector<tuple<int, int, int>> A(n);
	for (auto& [u, v, id] : A) {
		cin >> u >> v; u--, v--;
		id = m++;
	}

	DSU dsu(2*n+10);
	sort(all(A), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
		auto [ua, va, ida] = a;
		auto [ub, vb, idb] = b;
		return va - ua > vb - ub;
	});
	
	vector<int> res;
	for (int i = 0; i < n; i++) {
		auto [u, v, id] = A[i];
		if (dsu.find(u) == dsu.find(v)) continue;

		dsu.merge(u, v);
		res.push_back(id);
	}

	cout << res.size() << endl;
	for (int i : res) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
