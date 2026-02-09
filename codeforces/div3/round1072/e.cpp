#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<int> id, sz;
	ll s;

	Dsu(int n) : id(n), sz(n, 1), s(0LL) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : find(id[a]); }

	ll f(ll n) {
		return n * (n + 1) / 2 - n;
	}

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		s -= f(sz[a]), s -= f(sz[b]);
		sz[a] += sz[b], id[b] = a;
		s += f(sz[a]);
	}
};

int solve() {
	int n; cin >> n;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<array<int, 3>> C(n-1);
	for (int i = 0; i < n-1; i++) {
		C[i] = {abs(A[i] - A[i + 1]), i, i + 1};
	}
	sort(rall(C));

	Dsu dsu(n);
	vector<ll> R(n-1);
	for (int k = n-1, j = 0; k >= 1; k--) {
		while (j < n-1 and C[j][0] >= k) {
			dsu.merge(C[j][1], C[j][2]);
			j++;
		}
		R[k-1] = dsu.s;
	}

	for (int i = 0; i < n-1; i++) {
		cout << R[i] << " \n"[i==n-2];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

