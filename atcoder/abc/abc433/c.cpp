#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	ll res = 0;
	for (int l = 0, r, ult = 0, ultv = -10; l < n; l = r) {
		r = l + 1;
		while (r < n and S[r] == S[l]) {
			r++;
		}

		if (S[l] - '0' == ultv + 1) res += min(r - l, ult);
		ult = r - l;
		ultv = S[l] - '0';
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

