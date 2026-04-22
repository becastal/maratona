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
	vector<string> A(n), B(n);
	for (string& i : A) {
		cin >> i;
	}
	for (string& i : B) {
		cin >> i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (A[i][j] != B[i][j]) {
			return cout << i + 1 << ' ' << j + 1 << endl, 0;	
		}
	}
	assert(0);

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

