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
		string t = "1234567890", s; cin >> s;
		map<char, int> pos;
		for (int i = 0; i < (int)t.size(); i++) {
			pos[t[i]] = i;
		}

		int res = 0;
		for (int i = 0, j = 0; i < 4; i++) {
			if (t[j] != s[i]) {
				res += abs(pos[t[j]] - pos[s[i]]);
				j = pos[s[i]];
			}
		}
		cout << res + 4 << endl;
	}
    
    return(0);
}
