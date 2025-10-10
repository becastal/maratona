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
	map<char, int> cont;
	for (char c : s) cont[c]++;

	int v = min(cont['U'], cont['D']), h = min(cont['L'], cont['R']);
	if (!min(v, h)) {
		if (!v) {
			h = min(1, h);
			cout << 2 * h << endl << string(h, 'L') << string(h, 'R') << endl;
		} else {
			v = min(1, v);
			cout << 2 * v << endl << string(v, 'U') << string(v, 'D') << endl;
		}
	} else {
		cout << 2 * v + 2 * h << endl
			 << string(h, 'L') << string(v, 'U') << string(h, 'R') << string(v, 'D') << endl;	
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
