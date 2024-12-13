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

	string s, t; cin >> s >> t;
	int res = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		bool da = 1;
		for (int j = 0; j < (int)t.size(); j++) {
			if (i + j >= (int)s.size()) {
				da = 0;
				break;
			}
			
			da &= s[i + j] != t[j];
			if (!da) break;
		}
		res += da;
	}
	cout << res << endl;
    
    return(0);
}
