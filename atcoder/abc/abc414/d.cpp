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
	int cc = 0;
	vector<int> id, sz;
	vector<ll> L, R;
	DSU(int n, vector<ll> A) : id(n), sz(n, 1), L(A), R(A), cc(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		L[i] = min(L[i], L[j]);
		R[i] = max(R[i], R[j]);
		cc--;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<ll> A(n);

	for (ll& i : A) cin >> i;
	sort(all(A));
	DSU dsu(n, A);

	//for (int i : A) cout << i << ' '; cout << endl;
	vector<tuple<ll, int, int>> ed;
	for (int i = 1; i < n; i++) {
		ed.emplace_back(A[i] - A[i-1], i-1, i);
	}

	sort(all(ed));
	for (auto [w, a, b] : ed) {
		if (dsu.cc == m) break;
		dsu.merge(a, b);
	}

	set<int> S;
	for (int i = 0; i < n; i++) S.insert(dsu.find(i));
	
	ll res = 0;
	for (int u : S) {
		res += dsu.R[u] - dsu.L[u];
	}
	cout << res << endl;

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
