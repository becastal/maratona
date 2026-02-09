#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

res ta em dp[0][n];

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

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

struct KMPaut : vector<vector<int>> {
	KMPaut(){}
	KMPaut (string& s) : vector<vector<int>>(2, vector<int>(s.size()+1)) {
		vector<int> p = pi(s);
		auto& aut = *this;
		aut[s[0]-'('][0] = 1;
		for (char c = 0; c < 2; c++)
			for (int i = 1; i < s.size(); i++)
				aut[c][i] = s[i]-'(' == c ? i+1 : aut[c][p[i-1]];
	}
};

const int MOD = 1e9+7;
int solve() {
	int n; cin >> n;
	string S; cin >> S;
	int m = (int)S.size();

	KMPaut aut(S);
	for (int c = 0; c < 2; c++) {
		aut[c][m] = m;
	}

	vector<vector<int>> dp(2*n+1, vector<int>(m+1, 0)), dp_(dp);
	dp[0][0] = 1;

	for (int rep = 0; rep < 2 * n; rep++) {
		for (int i = 0; i <= 2 * n; i++) {
			fill(all(dp_[i]), 0);
		}

		for (int i = 0; i <= 2 * n; i++) {
			for (int j = 0; j <= m; j++) {
				for (int c = 0; c < 2; c++) {
					int i_ = i + (c ? -1 : +1), j_ = aut[c][j];
					if (i_ >= 0 and i_ <= 2 * n) {
						dp_[i_][j_] += dp[i][j];
						if (dp_[i_][j_] >= MOD) {
							dp_[i_][j_] -= MOD;
						}
					}
				}
			}
		}

		dp.swap(dp_);
		//for (int i = 0; i <= 2 * m; i++) {
		//	for (int j = 0; j <= m; j++) {
		//		cout << dp[i][j] << " \n"[j==n];
		//	}
		//}
		//cout << endl;
	}
	cout << dp[0][m] << endl;

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

