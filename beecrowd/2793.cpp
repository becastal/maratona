#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MOD = 1e9+7;
int solve() {
	string S; cin >> S;

	int c = 0;
	for (int i = 0, m = 0, f = 0; i < (int)S.size(); i++) {
		m += (S[i] == 'M');
		f += (S[i] == 'F');
		if (m == f) c++;
	}

	int res = 1;
	for (int i = 0; i < c-1; i++) {
		res = (res * 2) % MOD;	
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

