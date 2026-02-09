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
	Bit(int n_) : n(n_), F(n_+1, 0) {};
	void update(int i, int v) {
		for (i++; i <= n; i+=i&-i) F[i] += v;
	}

	ll pref(int i) {
		ll res = 0;
		for (i++; i; i-=i&-i) res += F[i];
		return res;
	}

	ll query(int l, int r) {
		if (r >= n) return 0LL;
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> A(n, vector<int>(m));
	priority_queue<array<int, 3>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			pq.push({-A[i][j], i, j});
		}
	}

	Bit bit(n);
	for (int i = 0; i < n; i++) {
		bit.update(i, +1);
	}

	ll res = 0;
	vector<vector<int>> R(n, vector<int>(m));

	for (int q = 0; q < n * m; q++) {
		auto [v, idi, idj] = pq.top(); pq.pop();
		R[idi][idj] = q;

		ll add = (n-1 - idi) * idj + bit.query(idi+1, n-1);
		res += add;
		bit.update(idi, +1);
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

