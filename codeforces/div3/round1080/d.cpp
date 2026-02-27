#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*
	f(1) = 0(a1) + 1(a2) + 2(a3) + 3(a4) + 4(a5) + ...
	f(2) = 1(a1) + 0(a2) + 1(a3) + 2(a4) + 3(a5) + ...
	f(3) = 2(a1) + 1(a2) + 0(a3) + 1(a4) + 2(a5) + ...

	x = f(1) - f(2) = -1(a1) + 1(a2) + 1(a3) + 1(a4) + ...
	y = f(2) - f(3) = -1(a1) - 1(a2) + 1(a3) + 1(a4) + ...

	x - y = 2(a2);
	a2 = (x - y) / 2;
*/

int solve() {
	int n; cin >> n;
	
	vector<int> F(n);
	for (int& i : F) {
		cin >> i;
	}

	vector<int> A(n);
	int s = 0, s_ = 0;
	for (int j = 1; j < n - 1; j++) {
		int i = j - 1, k = j + 1;

		int x = F[i] - F[j], y = F[j] - F[k];
		A[j] = (x - y) / 2;
		s += A[j] * (i + 1);
		s_ += A[j] * (n - (i + 1) - 1);
		//cout << (n - (i + 1) - 1) << " \n"[j==n-2];
	}
	A[n-1] = (F[0] - s) / (n - 1);
	A[0] = (F[n-1] - s_) / (n - 1);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " \n"[i==n-1];
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

