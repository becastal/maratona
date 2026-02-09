#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*
	maior sufixo de S que eh palindromo

	reverte S e depois da pra fazer com Z function
	- analisa a segunda parte de S + '$' + S
*/


int solve(string& S) {
	int n = (int)S.size();

	string S_ = S;
	reverse(all(S_));

	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S_[j] != S_[i]) j = P[j-1];
		P[i] = (j += S_[j] == S_[i]);
	}

	int res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j and S_[j] != S[i]) j = P[j-1];
		j += (S_[j] == S[i]);
		res = j;
	}

	int m = n - res;
	string R = S.substr(0, m);
	reverse(all(R));
	cout << S + R << endl;
	
	return(0);
}

signed main()
{
    _;

	string S;
	//int t = 1; //cin >> t;
	while (cin >> S) {
		solve(S);
	}
    
    return(0);
}

