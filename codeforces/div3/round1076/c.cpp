#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n), B(n);
	for (int& i : A) {
		cin >> i;
	}
	for (int& i : B) {
		cin >> i;
	}

	for (int i = n-1; i >= 0; i--) {
		if (i + 1 < n) {
			A[i] = max(A[i], A[i+1]);
		}
		A[i] = max(A[i], B[i]);
	}

	vector<int> P(n + 1);
	for (int i = 0; i < n; i++) {
		P[i + 1] = P[i] + A[i];
	}
	
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		cout << P[r] - P[l-1] << " \n"[i == q-1];
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

