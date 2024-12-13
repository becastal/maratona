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

	for (int i = 2; i < (int)s.size(); i++) {
		if (s[i] != s[i-1] and s[i] != s[i-2] and s[i-1] != s[i-2]) {
			return cout << s[i-2] << s[i-1] << s[i] << endl, 0;
		}
	}

	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i-1]) return cout << s[i-1] << s[i] << endl, 0;
	}
	
	cout << -1 << endl;
	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
