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
		return (u == id[u] ? u : id[u] = find(id[u]));
	}

	int merge(int a, int b) {
		if ((a = find(a)) == (b = find(b))) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		id[b] = a;
		return 1;
	}
};

signed solve() {
	int n, q; cin >> n >> q;

	vector<Dsu> D(11, Dsu(n));

	int res = 0;
	for (int i = 0, a, b, c; i < n - 1; i++) {
		cin >> a >> b >> c; a--, b--;
		for (int w = c; w <= 10; w++) {
			D[w].merge(a, b);
		}
		res += c;
	}

	for (int i = 0, a, b, c; i < q; i++) {
		cin >> a >> b >> c; a--, b--;

		int w_ = 10;
		while (w_ > 1 and D[w_-1].find(a) == D[w_-1].find(b)) w_--;

		for (int w = c; w <= 10; w++) {
			D[w].merge(a, b);
		}

		res += min(0LL, c - w_);
		cout << res << endl;
	}


	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
