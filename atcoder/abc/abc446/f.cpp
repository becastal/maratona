#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

// BIT
//
// BIT de soma 0-based
//
// upper_bound(x) retorna o menor p tal que pref(p) > x
//
// Complexidades:
// build - O(n)
// update - O(log(n))
// query - O(log(n))
// upper_bound - O(log(n))

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1);
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--)
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
	}

	set<int> Ruim;
	vector<int> R(n);
	for (int u = 0; u < n; u++) { 
		if (Ruim.count(u)) Ruim.erase(u);

		for (int v : G[u]) {
			if (v > u) {
				Ruim.insert(v);
			}
		}
		R[u] = Ruim.size();
	}

	priority_queue<int> pq; pq.push(0);
	vector<int> vis(n), O; vis[0] = 1;
	int t = 0;

	while (pq.size()) {
		int u = -pq.top(); pq.pop();
		O.push_back(u);
		O[t++] = u;

		for (int v : G[u]) if (!vis[v]) {
			vis[v] = 1;
			pq.push(-v);	
		}
	}

	Bit bit(n);
	for (int i = 0, j = 0; i < n; i++, j++) {
		if (i >= (int)O.size()) {
			R[i] = -1;
			continue;
		}

		//cout << O[i] << endl;
		//for (int j = 0; j < n; j++) {
		//	cout << bit.query(j, j) << " \n"[j==n-1];
		//}
		bit.update(O[i], + 1);
		if (bit.pref(j) != j + 1) {
			R[j] = -1;
		}
	}

	for (int i : R) {
		cout << i << endl;
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

