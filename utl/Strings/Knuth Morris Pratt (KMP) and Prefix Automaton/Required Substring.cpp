#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*
	dp[i][j]: quantas existem ate o pref i e com pi = j
	faz o automato ter um estado terminal com tudo apontando pra ele mesmo
	res ta em dp[n][m]
*/

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

struct KMPaut : vector<vector<int>> {
	KMPaut(){}
	KMPaut (string& s) : vector<vector<int>>(26, vector<int>(s.size()+1)) {
		vector<int> p = pi(s);
		auto& aut = *this;
		aut[s[0]-'A'][0] = 1;
		for (char c = 0; c < 26; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'A' == c ? i+1 : aut[c][p[i-1]];
	}
};

const int MOD = 1e9+7;
int solve() {
	int n; cin >> n;
	string A; cin >> A;
	int m = (int)A.size();

	KMPaut aut(A);
	for (int c = 0; c < 26; c++) {
		aut[c][m] = m;
	}

	vector<int> dp(m + 1, 0), dp_(m + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		fill(all(dp_), 0);

		for (int j = 0; j <= m; j++) {
			for (int c = 0; c < 26; c++) {
				int j_ = aut[c][j];
				dp_[j_] = (dp_[j_] + dp[j]) % MOD;
			}
		}

		dp.swap(dp_);
	}
	cout << dp[m] << endl;

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

