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
		string s; cin >> s;

		int res = 0;
		for (int i = 0, agr = 0; i < (int)s.size(); i++) {
			if (s[i] == '0') {
				agr++;
				continue;
			}

			res = max(res, agr + 1);
		}
		
		cout << (int)s.size() - res << endl;
	}
    
    return(0);
}
