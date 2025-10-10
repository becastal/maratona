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
	int n; cin >> n;
	string s; cin >> s;
	
	vector<vector<int>> ok(n, vector<int>(26, 0)), ok_(n, vector<int>(26, 0));
	if (s.size() == 3) return cout << (s[1] == s[0] or s[1] == s[2] ? "Yes" : "No") << endl, 0;

	for (int i = 0; i < n; i++) {
		if (i) ok[i] = ok[i-1];
		ok[i][s[i]-'a'] = 1;
	}

	for (int i = n-1; i >= 0; i--) {
		if (i != n-1) ok_[i] = ok_[i+1];
		ok_[i][s[i]-'a'] = 1;
	}

	for (int i = 1; i < n-1; i++) {
		if (ok[i-1][s[i]-'a'] or ok_[i+1][s[i]-'a']) return cout << "Yes" << endl, 0;
	}
	cout << "No" << endl;

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
