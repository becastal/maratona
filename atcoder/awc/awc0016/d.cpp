#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, q; cin >> n >> k >> q;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<int> F(n);
	for (int l = 0, r = 1, s = A[0]; l < n; l++) {
		while (r < n and s <= k) {
			s += A[r++];
		}
		F[l] = r;
		s -= A[l];
	}

	vector<int> P(n + 1);
	for (int i = 0; i < n; i++) {
		P[i+1] = P[i] + F[i];
	}

	while (q--) {
		int l, r; cin >> l >> r;
		cout << P[r] - P[l - 1] << endl;
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

