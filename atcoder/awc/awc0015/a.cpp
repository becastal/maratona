#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n = 7, res = 0;
	vector<int> A(n), B(n);
	for (int& i : A) {
		cin >> i;
	}
	for (int& i : B) {
		cin >> i;
	}

	for (int i = 0; i < 7; i++) {
		res += A[i] * B[i];
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

