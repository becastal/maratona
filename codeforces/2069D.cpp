#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	string s; cin >> s;

	int l = 0, r = (int)s.size()-1;
	for (; l < r and s[l] == s[r]; l++, r--); 
	if (l >= r) return cout << 0 << endl, 0;
	s = s.substr(l, r - l + 1);

	int n = (int)s.size(), res = n;
	for (int k = 0; k <= 1; k++) {
		if (k) reverse(s.begin(), s.end());

		auto da = [&](int t) {
			for (int i = t; i < n - t; ++i) {
				if (s[i] != s[n - 1 - i]) return 0;
			}

			int k = min(t, n - t);
			vector<int> cont(26, 0);
			for (int i = 0; i < t; ++i) {
				cont[s[i] - 'a']++;
			}
			for (int i = 0; i < k; ++i) {
				if (--cont[s[n - 1 - i] - 'a'] < 0) return 0;
			}
			for (int i : cont) if (i & 1) return 0;

			return 1;
		};

		int l = 1, r = n;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (da(m)) {
				res = min(res, m);	
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
	}
	cout << res << endl;

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
