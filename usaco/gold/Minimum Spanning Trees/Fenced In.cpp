#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<int> id, sz;

	Dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

int solve() {
	int a, b, n, m; cin >> a >> b >> n >> m;
	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
	sort(all(A));
	sort(all(B));

	int N = (n + 1) * (m + 1);
	Dsu dsu(N);
	vector<array<int, 3>> E(4 * N - 2 * (n + 1) - 2 * (m + 1));
	for (int i = 0, p = 0, ultai = 0; i <= n; i++) {
		int ai = (i < n ? A[i] : a);
		for (int j = 0, ultbj = 0; j <= m; j++) {
			int bj = (j < m ? B[j] : b);
			int l = ai - ultai;
			int h = bj - ultbj;
			if (j) {
				E[p++] = {l, j*(n+1)+i, (j-1)*(n+1)+i};
			}
			if (j != m) {
				E[p++] = {l, j*(n+1)+i, (j+1)*(n+1)+i};
			}
			if (i) {
				E[p++] = {h, j*(n+1)+i, j*(n+1)+i-1};
			}
			if (i != n) {
				E[p++] = {h, j*(n+1)+i, j*(n+1)+i+1};
			}
			if (j < m) ultbj = B[j];
		}
		if (i < n) ultai = A[i];
	}
	sort(all(E));
	ll res = 0;
	for (auto [w, u, v] : E) {
		if (dsu.find(u) != dsu.find(v)) {
			dsu.merge(u ,v);
			res += w;
		}
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("fencedin");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

