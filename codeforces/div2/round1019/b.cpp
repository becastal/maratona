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
	string s; cin >> s;

	int res = n;
	for (int i = 0, agr = 0; i < n; i++) {
		if (s[i] - '0' != agr) {
			res++;
			agr ^= 1;
		}
	}

//	string s_ = "";
//	for (int l = 0, r; l < n; l = r) {
//		r = l + 1;
//		while (s[r] == s[l]) {
//			r++;
//		}
//		s_.push_back(s[l]);
//	}

	if (res - n >= 3) res -= 2;
	else if (res - n >= 2) res--;
	cout << res << endl;

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
