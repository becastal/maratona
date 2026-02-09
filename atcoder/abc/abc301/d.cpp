#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S; cin >> S;
	ll n, res = 0; cin >> n;

	int m = (int)S.size();
	for (int i = 0; i < m; i++) if (S[i] == '1') {
		res += (1LL << (m - 1 - i));	
	}
	if (res > n) return cout << -1 << endl, 0;

	for (int i = 0; i < m; i++) if (S[i] == '?') {
		if (res + (1LL << (m - 1 - i)) <= n) {
			res += (1LL << (m - 1 - i));
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


