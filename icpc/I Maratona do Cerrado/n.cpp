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
	int m; cin >> m;

	auto b25 = [](int x) {
		string res = "aa";
		res[0] = char('a' + (x / 25));
		res[1] = char('a' + (x % 25));
		return res;
	};
	auto b25_ = [](string s) {
		return (s[0] - 'a') * 25 + (s[1] - 'a');
	};

	if (m == 1) {
		int n, x = 0; cin >> n;
		string s; cin >> s;
		
		for (int i = 0; i < n; i++) {
			x ^= (s[i] - 'a');
		}

		//dbg(x);
		//dbg(b25(x));
		//dbg(b25_(b25(x)));
		cout << s + s + b25(x) << endl;
	} else {
		int n; cin >> n;
		n = (n - 1) / 2;
		string s; cin >> s;

		string a = s.substr(0, n),
			   b = s.substr(n, n),
			   c = s.substr(2*n, 2);

		if (a == b) cout << a << endl;
		else {
			int x = 0;
			for (int i = 0; i < n; i++) {
				x ^= (s[i] - 'a');
			}
			cout << (x == b25_(c) ? a : b) << endl;
		}
	}

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
