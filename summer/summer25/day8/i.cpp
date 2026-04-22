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
	string T, A, B; cin >> T >> A >> B;
	int n = (int)A.size(), m = (int)B.size();

	// melhor score estando em i no automato de A e em j no automato de B
	vector<vector<int>> Dp(n, vector<int>(m, LLONG_MIN));
	KMPaut Ka(A), Kb(B);
	vector<int> Pa = pi(A), Pb = pi(B);

	Dp[0][0] = 0;
	for (char ch : T) {
		vector<vector<int>> Dp_(n, vector<int>(m, LLONG_MIN));

		int chi = 0, chj = 25;
		if (ch != '*') {
			chi = chj = ch - 'a';
		}

		for (int c = chi; c <= chj; c++) {
			for (int i = 0; i < n; i++) { 
				for (int j = 0; j < m; j++) if (Dp[i][j] != LLONG_MIN) {
					int i_ = Ka[c][i], j_ = Kb[c][j];
					int add = 0;
					if (i_ >= n) {
						i_ = Pa.back();
						add++;
					}
					if (j_ >= m) {
						j_ = Pb.back();
						add--;
					}
					Dp_[i_][j_] = max(Dp_[i_][j_], Dp[i][j] + add);
				}
			}
		}

		Dp = move(Dp_);
	}

	int res = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res = max(res, Dp[i][j]);
		}
	}
	cout << res << endl;

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

