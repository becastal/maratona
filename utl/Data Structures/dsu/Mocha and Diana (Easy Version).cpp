#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<int> id, sz;
	Dsu(int n) : id(n), sz(n, 1) {
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
	int n, m1, m2; cin >> n >> m1 >> m2;

	Dsu A(n), B(n);
	for (int i = 0, u, v; i < m1; i++) {
		cin >> u >> v; u--, v--;
		A.merge(u, v);
	}

	for (int i = 0, u, v; i < m2; i++) {
		cin >> u >> v; u--, v--;
		B.merge(u, v);
	}

	vector<array<int, 2>> R;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (A.find(i) != A.find(j) and B.find(i) != B.find(j)) {
				R.push_back({i, j});
				A.merge(i, j);
				B.merge(i, j);
			}
		}
	}

	cout << R.size() << endl;
	for (auto [u, v] : R) {
		cout << u+1 << ' ' << v+1 << endl;
	}

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

