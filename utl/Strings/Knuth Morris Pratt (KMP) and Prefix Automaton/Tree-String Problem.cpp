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
	int n; cin >> n;
		
	vector<vector<int>> G(n);
	vector<int> P(n, -1);
	vector<string> A(n);

	for (int i = 1; i < n; i++) {
		cin >> P[i] >> A[i]; P[i]--;
		G[P[i]].push_back(i);
		G[i].push_back(P[i]);
	}

	string S; cin >> S;
	int m = (int)S.size();
	vector<int> Pi = pi(S);
	KMPaut aut(S);

	stack<int> St;
	St.push(0);

	vector<int> J(n, 0);
	int res = 0;
	while (St.size()) {
		int u = St.top(); St.pop();
		
		if (u) {
			int j = J[P[u]];
			for (char c : A[u]) {
				if (S[j] != c) j = aut[c-'a'][j];
				j += (c == S[j]);
				if (j == m) res++, j = Pi[m-1];
			}
			J[u] = j;
		}

		for (int v : G[u]) if (v != P[u]) {
			St.push(v);	
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

