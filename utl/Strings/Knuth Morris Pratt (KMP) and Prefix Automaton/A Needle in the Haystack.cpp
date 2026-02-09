#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve(int n, string& S, string& T) {
	int m = (int)T.size();

	vector<int> P(n), R;
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[i] != S[j]) j = P[j-1];
		P[i] = (j += S[i] == S[j]);
	}

	for (int i = 0, j = 0; i < m; i++) {
		while (j and S[j] != T[i]) j = P[j-1];
		if (S[j] == T[i]) j++;
		if (j == n) j = P[j-1], R.push_back(i - n + 1);
	}

	for (int i : R) {
		cout << i << endl;
	}

	return(0);
}

signed main()
{
    _;

	int n, t = 0; //cin >> t;
	string S, T;
	while (cin >> n >> S >> T) {
		if (t++) cout << endl;
		solve(n, S, T);
	}
    
    return(0);
}

