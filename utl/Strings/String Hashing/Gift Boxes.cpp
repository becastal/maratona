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

int solve() {
	string S, T; cin >> S >> T;
	int n = (int)S.size(), res = 0;
	auto P = pi(S);

	stack<int> St; St.push(0);
	for (char c : T) {
		int j = St.top();
		while (j and S[j] != c) j = P[j - 1];
		j += (S[j] == c);
		St.push(j);

		if (St.top() == n) {
			for (int i = 0; i < n; i++) {
				St.pop();
			}
			res++;
		}
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

