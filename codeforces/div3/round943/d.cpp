#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k, pa, pb; cin >> n >> k >> pa >> pb; pa--, pb--;
	vector<int> P(n), A(n);
	for (int& i : P) cin >> i, i--;

//	for (int u = 0; u < n; u++) {
//		cout << u+1 << ' ' << P[u]+1 << endl;
//	}

	for (int& i : A) cin >> i;

	auto calc = [&](int in) {
		vector<int> vis(n, 0);

		ll res = 0, k_ = k, s = 0;
		for (int u = in; !vis[u] and k_; u = P[u]) {
			res = max(res, s + A[u] * k_--);
			s += A[u];
			vis[u] = 1;
		}
		return res;
	};

	ll a = calc(pa), b = calc(pb);
	if (a == b) return cout << "Draw" << endl, 0;
	cout << (a > b ? "Bodya" : "Sasha") << endl;

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

