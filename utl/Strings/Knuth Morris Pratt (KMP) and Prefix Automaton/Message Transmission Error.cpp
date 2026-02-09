#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[j] != S[i]) j = P[j-1];
		P[i] = (j += S[j] == S[i]);
	}

	if (P[n-1] <= n / 2) return cout << "NO" << endl, 0;
	cout << "YES" << endl << S.substr(0, P[n-1]) << endl;

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

