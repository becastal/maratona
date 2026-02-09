#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	/*
		vale mais a pena quebrar todos os 00s antes.
		a cada 000 eu consigo gastar 1 e c00 -= 2
		000000
	*/

	int c11 = 0, c00 = 0;
	for (int i = 0; i < n-1; i++) {
		c11 += S[i] == '1' and S[i+1] == '1';
		c00 += S[i] == '0' and S[i+1] == '0';
	}

	if (c11 >= c00) return cout << 0 << endl, 0;

	int res = 0;
	for (int i = 0; i < n-2 and c00 > c11; i++) {
		if (S[i] == '0' and S[i+1] == '0' and S[i+2] == '0') {
			res++;
			S[i+1] = '1';	
			c00 -= 2;
		}
	}

	for (int i = 0; i < n-1 and c00 > c11; i++) {
		if (S[i] == '0' and S[i+1] == '0') {
			res++;
			S[i+1] = '1';
			c11++, c00--;
		}
	}
	cout << res << endl;

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

