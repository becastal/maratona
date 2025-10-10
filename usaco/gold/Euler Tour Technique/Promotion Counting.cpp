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

struct Bit {
	int n;
	vector<int> f;
	Bit(int n_) : n(n_), f(n_+1, 0) {};
	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) f[i] += x;
	}
	int pref(int i) {
		int res = 0;
		for (++i; i; i -= i & -i) res += f[i];
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<vector<int>> G(n);
	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[i].push_back(p);
		G[p].push_back(i);
	}

	int t = 0;
	vector<int> L(n), R(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			dfs(v, u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	Bit bit(n);
	vector<int> res(n), P(n);
	iota(all(P), 0);
	sort(all(P), [&](int i, int j) { return A[i] > A[j]; });
	for (int u : P) {
		res[u] = bit.query(L[u], R[u]);
		bit.update(L[u], +1);
	}
	for (int i : res) cout << i << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("promote");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

