#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Bit {
	int n;
	vector<int> a;

	Bit(int n_) : n(n_), a(n + 1) { }
	void update(int i, int x) {
		for (i++; i <= n; i += i&-i) {
			a[i] += x;
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i -= i&-i) {
			res += a[i];
		}
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l);
	}
};

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);
	vector<int> Y(n);

	for (int i = 0; i < n; i++) {
		auto& [x, y] = A[i];
		cin >> x >> y;
		int u = x + y, v = x - y;
		x = u, y = v;
		Y[i] = y;
	}
	sort(all(Y));
	Y.erase(unique(all(Y)), Y.end());
	int m = (int)Y.size();

	auto id = [&](int a) {
		return lower_bound(all(Y), a) - Y.begin();
	};

	sort(all(A));

	int res = 0;
	vector<Bit> bit_cont(2, Bit(m)), bit_soma(2, Bit(m));
	for (int i = 0, somax[2] = {0, 0}, contx[2] = {0, 0}; i < n; i++) {
		auto [x, y] = A[i];	
		int idy = id(y), p = x & 1;
		contx[p]++;
		somax[p] += x;
		bit_cont[p].update(idy, +1);
		bit_soma[p].update(idy, +y);

		int total = contx[p] * x - somax[p];
		int cont_menores = bit_cont[p].pref(idy), cont_maiores = contx[p] - cont_menores;
		int soma_menores = bit_soma[p].pref(idy), soma_maiores = bit_soma[p].pref(m - 1) - soma_menores;


		total += cont_menores * y - soma_menores;
		total += soma_maiores - cont_maiores * y;
		res += total / 2;
	}
	cout << res << endl;

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

