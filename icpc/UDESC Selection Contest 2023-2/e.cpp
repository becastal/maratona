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
	string s, res = "";; cin >> s;

	for (int i = 0; i < n; ) {
		if (i + 1 < n and s[i] == 'a' and s[i+1] == 'b') {
			if (i + 2 < n and s[i+2] == 'a' and (i + 3 == n or (i + 3 < n and s[i + 3] == 'a'))) {
				res.push_back('1');
				i += 3;
			} else {
				res.push_back('0');
				i += 2;	
			}
		} else return cout << ":(" << endl, 0;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
