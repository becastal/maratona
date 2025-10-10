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
	int n; cin >> n;

	vector<tuple<int, int, int>> ed(n * n);
	vector<vector<int>> A(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i) ed.emplace_back(abs(A[i][j] - A[i-1][j]), i * n + j, (i - 1) * n + j);
			if (j) ed.emplace_back(abs(A[i][j] - A[i][j-1]), i * n + j, i * n + (j - 1));
			if (i + 1 < n) ed.emplace_back(abs(A[i][j] - A[i+1][j]), i * n + j, (i + 1) * n + j);
			if (j + 1 < n) ed.emplace_back(abs(A[i][j] - A[i][j+1]), i * n + j, i * n + (j + 1));
		}
	}
	sort(all(ed));

	DSU dsu(n * n);
	for (auto& [w, u, v] : ed) {
		dsu.merge(u, v);
		if (dsu.sz[dsu.find(u)] >= (n * n + 1) / 2) return cout << w << endl, 0;
	}
	assert(0);

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("tractor");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

