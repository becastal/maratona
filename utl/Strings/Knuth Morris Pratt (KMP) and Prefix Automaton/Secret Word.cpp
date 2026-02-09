#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

maior prefixo de S que aparece revertido em S
bb + kmp?

*/

int solve() {
	string S; cin >> S;
	int n = (int)S.size();
	string S_(S);
	reverse(all(S_));

	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[j] != S[i]) j = P[j-1];
		P[i] = (j += S[j] == S[i]);
	}

	int res = 1;
	for (int i = 0, j = 0; i < n; i++) {
		while (j and S[j] != S_[i]) j = P[j-1];
		j += S[j] == S_[i];
		res = max(res, j);
	}

	string R = S.substr(0, res);
	reverse(all(R));
	cout << R << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

