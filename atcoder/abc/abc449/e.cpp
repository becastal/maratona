#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define int ll


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
	int n, m, mxf = 0; cin >> n >> m;

	vector<int> A(n), F(m+1, 0);
	for (int& i : A) { 
		cin >> i;
		mxf = max(mxf, ++F[i]);
	}

	Bit bit(n + 1);
	vector<vector<int>> FB(n + 1);
	for (int i = 1; i <= m; i++) {
		bit.update(F[i], +1);
		FB[F[i]].push_back(i);
	}

	int q; cin >> q;
	vector<int> Res(q);
	vector<array<int, 2>> Q(q);
	for (int i = 0, x; i < q; i++) {
		cin >> x; x--;
		Q[i] = {x, i};
	}
	sort(all(Q));

	vector<vector<array<int, 2>>> Qu(n + 1);
	int etapa = 0, foi = 0, pre = mxf * m - n;
	for (auto& [x, id] : Q) {
		if (x < n) {
			Res[id] = A[x];	
			continue;
		}

		x -= n;
		if (x >= pre) {
			Res[id] = (x - pre) % m + 1;
			continue;
		}

		while (x >= foi + bit.pref(etapa)) {
			foi += bit.pref(etapa++);
		}
		
		Qu[etapa].push_back({x - foi, id});
		// Res[id] = (x - foi)esimo menor valor no prefixo em que fi <= etapa
	}

	ordered_set Oss;
	for (int freq = 0; freq <= n; freq++) {
		for (int i : FB[freq]) {
			Oss.insert(i);	
		}

		for (auto [pos, id] : Qu[freq]) {
			Res[id] = *Oss.find_by_order(pos);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << Res[i] << endl;
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

