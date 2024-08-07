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

void solve() {
	string s, t; cin >> s >> t;
	int n = (int)s.size(), m = (int)t.size();
	
	int r = 0;
	for (int l = 0; l < n; l++) {
		if (s[l] == '?') {
			if (r < m) s[l] = t[r++];
			else s[l] = 'a' + rand() % 26;
		} else if (s[l] == t[r]) r++;
	}
	
	if (r >= m) {
		cout << "YES" << endl << s << endl;
	} else {
		cout << "NO" << endl;
	}
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
