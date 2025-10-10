#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
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
	int m, n, k; cin >> m >> n >> k;

	DSU dsu(k+4);
	vector<array<int, 3>> A(k);

	auto toca = [&](int a, int b) {
		auto [xa, ya, sa] = A[a];
		auto [xb, yb, sb] = A[b];
		return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) <= sa + sb;
	};
	for (auto& [x, y, s] : A) {
		cin >> x >> y >> s;
	}

	for (int i = 0; i < k; i++) {
		for (int j = i+1; j < k; j++) {
			if (toca(i, j)) dsu.merge(i+4, j+4);
		}
		auto [x, y, s] = A[i];
		if (y + s >= n) dsu.merge(0, i+4);
		if (x + s >= m) dsu.merge(1, i+4);
		if (y - s <= 0) dsu.merge(2, i+4);
		if (x - s <= 0) dsu.merge(3, i+4);
	}

	int ruim = 0;
	ruim |= (dsu.find(0) == dsu.find(1));
	ruim |= (dsu.find(0) == dsu.find(2));
	ruim |= (dsu.find(3) == dsu.find(1));
	ruim |= (dsu.find(3) == dsu.find(2));
	cout << (ruim ? "N" : "S") << endl;

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
