#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		A.push_back(A[i]);
	}

	vector<ll> P(2*n+1, 0);
	for (int i = 1; i <= 2*n; i++) {
		P[i] = P[i-1] + A[i-1];
	}

	int c = 0;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int x; cin >> x;
			c += x, c %= n;
		} else {
			int l, r; cin >> l >> r;
			cout << P[c+r] - P[c+l-1] << endl;
		}
	}

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

