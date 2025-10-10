#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<int> F;
	Bit(int n_) : n(n_), F(n+1, 0) {};
	void add(int i, int x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;
	}
	int pref(int i) {
		int res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(n), P(n+1);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		P[A[i]] = i;
	}

	vector<vector<int>> Pdiv(n+1);
	for (int a = 1; a <= n; a++) {
		int l = P[a];
		for (int b = a; b <= n; b += a) {
			int r = P[b], l_, r_;
			tie(l_, r_) = minmax(l, r);
			Pdiv[r_].push_back(l_);
		}
	}

	Bit bit(n);
	vector<int> R(m);
	vector<vector<array<int, 3>>> Q(n);

	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r; l--, r--;
		Q[r].push_back({l, r, i});
	}

	for (int i = 0; i < n; i++) {
		for (int j : Pdiv[i]) {
			bit.add(j, +1);
		}

		for (auto [l, r, id] : Q[i]) {
			R[id] = bit.query(l, n-1);
		}
	}
	for (int i : R) cout << i << endl;


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

