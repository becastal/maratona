#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<ll> F;
	Bit(int n_) : n(n_), F(n_ + 1, 0) {}

	void update(int i, int x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;
	}
	ll pref(int i) {
		ll res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	ll query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

const int MAX = 1e5+10;
int F[MAX];

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int t = 0;
	vector<int> L(n), R(n), E(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		E[t] = A[u];
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			dfs(v, u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	vector<array<int, 4>> Q(q);
	for (int i = 0, u, x; i < q; i++) {
		cin >> u >> x; u--;
		Q[i] = {L[u], R[u], x, i};
	}

	int tam = ceil(sqrt(n));
	sort(all(Q), [&tam](auto& a, auto& b) {
		return make_pair(a[0] / tam, a[1]) < make_pair(b[0] / tam, b[1]);
	});

	memset(F, 0, sizeof(F));
	Bit bit(n);
	auto add = [&](int i) {
		if (F[E[i]]) bit.update(F[E[i]], -1);
		bit.update(++F[E[i]], +1);
	};
	auto rem = [&](int i) {
		bit.update(F[E[i]], -1);
		bit.update(--F[E[i]], +1);
	};
	auto cont = [&](int x) {
		if (x > n) return 0LL;
		return bit.query(x, n-1);
	};

	vector<ll> Rs(q);
	int agrl = 0, agrr = -1;
	for (auto [l, r, x, id] : Q) {
		while (agrr < r) add(++agrr);
		while (agrl > l) add(--agrl);
		while (agrl < l) rem(agrl++);
		while (agrr > r) rem(agrr--);
		Rs[id] = cont(x);
	}

	for (ll i : Rs) cout << i << endl;

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

