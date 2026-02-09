#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

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
	string S; cin >> S;

	map<int, int> C = {{0, 1}}, val = {{'A', +1}, {'B', -1}, {'C', +0}};

	//int res = 0;
	//for (int s = 1; s <= n; s++) {
	//	int agr = 0;
	//	map<int, int> M = {{0, 1}};
	//	for (int i = 0, p = 0; i < n; i++) {
	//		p += val[S[i]];
	//		agr += M[p - s]; // para todo s menor que p?
	//		M[p]++;
	//	}
	//	res += agr;
	//}
	//cout << res << endl;

	Bit bit(2 * n + 1);
	bit.update(n, +1);
	ll res = 0;
	for (int i = 0, p = 0; i < n; i++) {
		p += val[S[i]];
		res += bit.pref(p - 1 + n);
		bit.update(p + n, +1);
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

