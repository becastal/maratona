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

template<typename T> int kmp(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) return 1;
	}
	return 0;
}

int solve() {
	vector<string> A(3);
	for (auto& i : A) {
		cin >> i;
	}
	vector<int> P = {0, 1, 2};

	auto calc = [](string& s, string& t) {
		auto p = pi(t);	
		int j = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			while (j and s[i] != t[j]) j = p[j-1];
			j += s[i] == t[j];
		}
		return j;
	};

	int res = LLONG_MAX;
	do {
		string s = A[P[0]];
		for (int i = 1; i < 3; i++) {
			if (kmp(A[P[i]], s)) continue;
			// maior pref de mim que eh suf dele.
			s += A[P[i]].substr(calc(s, A[P[i]]));
		}
		res = min(res, (int)s.size());	
	} while (next_permutation(all(P)));
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

