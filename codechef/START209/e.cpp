#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	010 eh ganho
	01*0 eh ganho

	impressao que bob pode sempre foder
	alice ganha ou de cara ou no primeiro mov

*/

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	int c01 = 0, c10 = 0;
	for (int i = 1; i < n; i++) {
		c01 += S[i-1] == '0' and S[i] == '1';
		c10 += S[i-1] == '1' and S[i] == '0';
	}

	int ok = (c01 and c10);
//	for (int i : {0, n-1}) {
//		int c01_ = c01, c10_ = c10;
//
//		if (i) {
//			c01_ -= (S[i-1] == '0' and S[i] == '1');
//			c10_ -= (S[i-1] == '1' and S[i] == '0');
//		}
//		if (i + 1 < n) {
//			c01_ -= (S[i] == '0' and S[i+1] == '1');
//			c10_ -= (S[i] == '1' and S[i+1] == '0');
//		}
//
//		if (i and i + 1 < n) {
//			c01_ += (S[i-1] == '0' and S[i+1] == '1');
//			c10_ += (S[i-1] == '1' and S[i+1] == '0');
//		}
//		ok |= (c01_ == c10_ and c01_ > 0);
//	}
	cout << (ok ? "Alice" : "Bob") << endl;


	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

