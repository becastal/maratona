#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

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
		aut[s[0]-'a'][0] = 1;
		for (char c = 0; c < 26; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'a' == c ? i+1 : aut[c][p[i-1]];
	}
};

int solve() {
	string S, T; cin >> S >> T;
	int n = (int)S.size(), m = (int)T.size();

	auto P = pi(T);
	KMPaut aut(T);

	vector<int> dp(m + 1, LLONG_MIN), dp_(m + 1, LLONG_MIN);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		fill(all(dp_), LLONG_MIN);

		if (S[i] == '?') {
			for (int j = 0; j < m; j++) if (dp[j] != LLONG_MIN) {
				for (int c = 0; c < 26; c++) {
					int j_ = aut[c][j], add = 0;
					if (j_ == m) j_ = P[j_-1], add = 1;

					dp_[j_] = max(dp_[j_], dp[j] + add);
				}
			}
		} else {
			for (int j = 0; j < m; j++) if (dp[j] != LLONG_MIN) {
				int c = S[i] - 'a';
				int j_ = aut[c][j], add = 0;
				if (j_ == m) j_ = P[j_-1], add = 1;

				dp_[j_] = max(dp_[j_], dp[j] + add);
			}
		}

		dp.swap(dp_);
	}
	cout << *max_element(all(dp)) << endl;
	
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

