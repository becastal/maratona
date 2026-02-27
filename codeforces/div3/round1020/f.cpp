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
	vector<int> sz, id, tam;

	Dsu (int n_) : n(n_), sz(n, 1), id(n), tam(n) {
		iota(all(id), 0);
	}

	int find(int a) {
		return a == id[a] ? a : id[a] = find(id[a]);
	}

	int merge(int a, int b) {
		if ((a = find(a)) == (b = find(b))) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		tam[a] += tam[b];
		id[b] = a;
		return 1;
	}
};

int solve() {
	int n, m = 0; cin >> n;
	string S; cin >> S;

	vector<array<int, 2>> seg;
	vector<vector<int>> id(n);

	for (int i = 0; i < n; i++) {
		if (S[i] == '0') {
			if (i) {
				seg.push_back({0, i - 1});
				id[i].push_back(m++);
			} 

			if (i < n - 1) {
				seg.push_back({i+1, n-1});
				id[i].push_back(m++);
			}
		} else {
			seg.push_back({i, i});
			id[i].push_back(m++);
		}
	}

	Dsu dsu(m);
	for (int i = 0; i < m; i++) {
		dsu.tam[i] = seg[i][1] - seg[i][0] + 1;
		//cout << "(" << seg[i][0] << ", " << seg[i][1] << "): " << dsu.tam[i] << endl;
	}

	auto intersec = [&](auto& i, auto& j) {
		auto [l, r] = i;
		auto [a, b] = j;
		
		if (r < a or l > b) return 0;
		return 1;
	};

	for (int i = 1; i < n; i++) {
		for (int a : id[i]) {
			for (int b : id[i-1]) {
				if (intersec(seg[a], seg[b])) {
					dsu.merge(a, b);
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < m; i++) {
		res = max(res, dsu.tam[dsu.find(i)]);
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

