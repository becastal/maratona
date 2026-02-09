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
	string S; cin >> S;

	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[i] != S[j]) j = P[j-1];
		P[i] = (j += S[i] == S[j]);
	}

	for (int i = 1; i < n; i++) {
		int t = (i + 1) - P[i];
		if ((i + 1) % t == 0 and (i + 1) / t != 1) {
			cout << (i + 1) << ' ' << (i + 1) / t  << endl;
		}
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Test case #" << (i + 1) << endl;
		solve();
		cout << endl;
	}
    
    return(0);
}

