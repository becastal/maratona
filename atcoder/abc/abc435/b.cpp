#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int res = 0;
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			int s = 0;
			for (int i = l; i <= r; i++) {
				s += A[i];
			}

			int ok = 1;
			for (int i = l; i <= r and ok; i++) {
				ok &= s % A[i] != 0;
			}
			res += ok;
		}
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

