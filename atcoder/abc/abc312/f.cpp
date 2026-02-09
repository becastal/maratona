#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	query de soma dos maiores k valores;

	usando 0 dos de tipo 2: soma dos m maiores que sao Ti == 0
	usando 1 dos de tipo 2: 
		soma dos (m - 1) maiores que sao Ti == 0 
		concatenados com max(Xi dos de Ti == 2) valores em que Ti == 1
	...
*/

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
		//printf("i: %d\n", i);
		if (i < 0) return 0LL;
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

	vector<int> B;
	vector<priority_queue<int>> A(3);
	for (int i = 0, t, x; i < n; i++) {
		cin >> t >> x;
		A[t].push(x);	
		B.push_back(x);
	}

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	int nn = (int)B.size();

	Bit Bc(nn), Bs(nn);
	auto add = [&](int x) {
		int p = lower_bound(all(B), x) - B.begin();
		Bc.update(p, +1);
		Bs.update(p, +x);
	};

	auto query = [&](int kk) -> ll int{
		ll tc = Bc.pref(nn - 1), ts = Bs.pref(nn - 1);

		if (kk <= 0) return 0LL;
		if (kk >= tc) return ts;

		ll k = tc - kk;
		int p = Bc.upper_bound(k - 1);

		ll cantes = Bc.pref(p - 1);
		ll santes = Bs.pref(p - 1);

		ll need = k - cantes;
		ll sumSmallest = santes + need * 1LL * B[p];

		return ts - sumSmallest;
	};

	while (A[0].size()) {
		add(A[0].top());
		A[0].pop();
	}

	ll res = query(m);
	for (int i = 0; i < m and A[2].size(); i++) {
		for (int j = 0; j < A[2].top() and A[1].size(); j++) {
			add(A[1].top());
			A[1].pop();
		}
		A[2].pop();
		res = max(res, query(m - i - 1));
	}
	cout << res << endl;

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

