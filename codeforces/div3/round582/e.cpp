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
	string s, t, r = "abc"; cin >> s >> t;

	int ok = 0;
	do {
		int bom = 1;
		for (int i = 0; i < 3; i++) {
			bom &= !(r[i] == s[0] and r[(i+1)%3] == s[1]);	
			bom &= !(r[i] == t[0] and r[(i+1)%3] == t[1]);	
		}
		if (bom) {
			ok = 1;
			break;
		}

		string g = string(n, r[0]) + string(n, r[1]) + string(n, r[2]); 
		if (g.find(s) == string::npos and g.find(t) == string::npos) {
            return cout << "YES" << endl << g << endl, 0;
        }
	

	} while (next_permutation(r.begin(), r.end()));

	if (ok) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << r;
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1;// cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
