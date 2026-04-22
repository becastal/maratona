#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n;
	vector<int> id, sz;

	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int u) {
		return u == id[u] ? u : id[u] = find(id[u]);	
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = u;
		return 1;
	}
};

int solve() {
	int n, p; cin >> n >> p;
	vector<int> A(n), O(n), Foi(n);
	vector<array<int, 3>> E;

	for (int i = 0; i < n; i++){ 
		cin >> A[i];
		if (i) {
			E.push_back({p, i-1, i});
		}
	}

	iota(all(O), 0);
	sort(all(O), [&](int a, int b) {
		return A[a] < A[b];
	});

	for (int i : O) {
		for (int j = i; j and !Foi[j-1] and A[j-1] % A[i] == 0; j--) {
			E.push_back({A[i], i, j-1});
			Foi[j-1] = 1;
		}
		for (int j = i; j + 1 < n and !Foi[j] and A[j+1] % A[i] == 0; j++) {
			E.push_back({A[i], i, j+1});
			Foi[j] = 1;
		}
	}

	Dsu dsu(n);
	sort(all(E));
	int res = 0;
	for (auto [w, u, v] : E) {
		res += dsu.merge(u, v) * w;
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

