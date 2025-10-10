#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		for (int j = 0; j < k; j++) if (S[j] == '1') {
			A[i] |= (1 << j);
		}
	}

	int res = k;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res = min(res, __builtin_popcount(A[i] ^ A[j]));
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

