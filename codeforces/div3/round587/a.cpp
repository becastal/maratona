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
	int n, res = 0; cin >> n;

	string s;
	for (int i = 0; i < n / 2; i++) {
		char c, c_; cin >> c >> c_;

		if (c == c_) {
			res++;
			s.push_back(c), s.push_back(c == 'a' ? 'b' : 'a');
		} else s.push_back(c), s.push_back(c_);
	}
	cout << res << endl << s << endl;

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
