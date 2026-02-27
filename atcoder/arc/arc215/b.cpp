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
	int n; cin >> n;

	vector<int> L(2 * n, -1);
	vector<int> A(2 * n), vis(n + 1, -1);
	for(int i = 0; i < 2 * n; i++) {
		cin >> A[i];
		if (vis[A[i]] != -1) {
			L[i] = vis[A[i]];	
		}
		vis[A[i]] = i;
	}

	Bit bit(2 * n);
	vector<int> R;
	for (int i = 0; i < 2 * n; i++) if (L[i] != -1) {
		if (bit.query(L[i], i) & 1 ^ 1) {
			bit.update(i, +1);
			R.push_back(i);
		}
	}

	int k = (int)R.size();
	cout << k << endl;
	for (int i = 0; i < k; i++) {
		cout << R[i] << " \n"[i==k-1];
	}

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

