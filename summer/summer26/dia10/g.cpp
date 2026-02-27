#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n; cin >> n;
	vector<int> A(n), B(n);

	for (int& i : A) {
		cin >> i;
	}
	for (int& i : B) {
		cin >> i;
	}

	vector<int> S(3), R(3);
	for (int i = 0; i < n; i++) {
		S[i % 3] += B[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			R[j] += A[i] * S[((j - i % 3) + 3) % 3];
		}
	}
	cout << R[1] << ' ' << R[2] << ' ' << R[0] << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    //
    return(0);
}
