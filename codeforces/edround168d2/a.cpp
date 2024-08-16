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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		string s, res; cin >> s;
		bool foi = false;
		
		res.push_back(s[0]);
		for (int i = 1; i < s.size(); i++) {
			if (!foi and s[i] == s[i - 1]) {
				foi = true;	

				for (int j = 0; j < 26; j++) {
					if (s[i] != 'a' + j) {
						res.push_back(char('a' + j));
						break;
					}
				}
			}
			res.push_back(s[i]);
		}

		if (!foi) {
			for (int i = 0; i < 26; i++) {
				if (s[0] != 'a' + i) {
					res = char('a' + i) + s;
					break;
				}
			}
		}
		cout << res << endl;
	}
    
    return(0);
}
