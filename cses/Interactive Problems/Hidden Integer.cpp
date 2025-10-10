#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	auto query = [](int x) {
		cout << "? " << x << endl;	
		string s; cin >> s; return s == "YES";
	};

	int l = 1, r = (int)1e9+10, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (query(m)) {
			l = m + 1;
		} else {
			res = m;
			r = m - 1;
		}
	}
	cout << "! " << res << endl;

	return(0);
}

int main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
