#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	string s;
	while (cin >> s and s != "-1") {
		if (s.size() > 1 and s[0] == '0' and s[1] == 'x') {
			ll res = 0;
			for (int i = 2; i <(int)s.size(); i++) {
				res *= 16;
				if (s[i] >= '0' and s[i] <= '9') {
					res += s[i] - '0';
				} else if (s[i] >= 'A' and s[i] <= 'F') {
					res += s[i] - 'A' + 10;
				} else if (s[i] >= 'a' and s[i] <= 'f') {
					res += s[i] - 'a' + 10;
				} 
			}
			cout << res << endl;
		} else {
			ll num = stoll(s);

			if (!num) {
				cout << "0x0" << endl;
				continue;
			}

			string res = "";
			while (num) {
				int r = num % 16;
				res.push_back((r < 10) ? ('0' + r) : ('A' + (r - 10)));
				num /= 16;
			}
			reverse(res.begin(), res.end());

			cout << "0x" << res << endl;
		}
	}
    
    return(0);
}
