#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n), C(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
	for (int& i : C) cin >> i;

	vector<int> S(n), Mx(n+1, LLONG_MIN);
	for (int i = n-1, s = 0; i >= 0; i--) {
		S[i] = (s += C[i] - B[i]);	
		Mx[i] = max(Mx[i + 1], S[i]);
	}

	int sb = accumulate(all(B), 0LL), res = LLONG_MIN;
	for (int i = 0, s = 0; i + 2 < n; i++) {
		s += A[i] - B[i];
		res = max(res, s + sb + Mx[i + 2]);
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

