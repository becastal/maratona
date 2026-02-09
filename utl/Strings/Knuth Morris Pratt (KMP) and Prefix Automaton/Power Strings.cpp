#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve(string& S) {
	int n = (int)S.size();
	
	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[i] != S[j]) j = P[j-1];
		P[i] = (j += S[i] == S[j]);
	}

	vector<int> R;
	int t = n - P[n-1];
	int res = (n % t == 0 ? n / t : 1);
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1;
	string S;
	while (cin >> S and S != ".") {
		solve(S);
	}
    
    return(0);
}

