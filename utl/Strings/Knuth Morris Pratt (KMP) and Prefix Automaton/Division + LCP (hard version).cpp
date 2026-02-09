#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

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

const int MAX = 2e5+10;
int memo[MAX];
int solve() {
	memset(memo, -1, sizeof(memo));
	int n, a, b; cin >> n >> a >> b;
	string S; cin >> S;

	auto da = [&](int m) { 
		if (memo[m] != -1) return memo[m];
		string A(S.begin(), S.begin() + m);
		vector<int> P = matching(A, S);

		int cont = 0;
		for (int i = 0, j = 0; i < P.size(); i++) {
			if (P[i] < j) continue;
			j = P[i] + m;
			cont++;
		}

		return memo[m] = cont;
	};

	
	for (int i = a; i <= b; i++) {
		int l = 1, r = n, res = 0;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (da(m) >= i) {
				l = m+1;
				res = m;
			} else {
				r = m-1;
			}
		}
		cout << res << " \n"[i==b];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
