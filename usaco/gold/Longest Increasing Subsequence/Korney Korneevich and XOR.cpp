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
	vector<int> A(n);

	vector<int> Dp(501, 0);
	Dp[0] = 1;

	for (int a : A) {
		vector<int> Dp_(501, 0);

		for (int i = 0; i < a; i++) {
		
		}
		
		Dp = move(Dp_);
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

