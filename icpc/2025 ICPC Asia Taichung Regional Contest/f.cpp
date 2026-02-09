#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	int n;
	vector<int> sz, id;

	Dsu(int n_) : n(n_), sz(n_, 1), id(n_) {
		iota(all(id), 0);
	}

	int find(int a) {
		return a == id[a] ? a : id[a] = find(id[a]);
	}

	int merge(int a, int b) {
		if ((a = find(a)) == (b = find(b))) return 0;
		if (sz[b] > sz[a]) swap(a, b);
		sz[a] += sz[b];
		id[b] = id[a];
		return 1;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> P(n);

	for (int& i : P) cin >> i;

	vector<array<int, 3>> E;
	int ga = P[0];
	for (int i = 1; i < n; i++) {
		ga = gcd(ga, P[i]);
		E.push_back({ga, 0, i});
	}

	int gb = P[n-1];
	for (int i = n-2; i >= 0; i--) {
		gb = gcd(gb, P[i]);
		E.push_back({gb, n-1, i});
	}

	sort(all(E));

	ll res = 0;
	Dsu dsu(n);
	for (auto [w, a, b] : E) {
		if (dsu.merge(a, b)) {
			res += w;
		}
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

