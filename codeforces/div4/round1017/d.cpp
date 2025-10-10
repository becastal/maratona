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
	
	string a, b; cin >> a >> b;
	int n = (int)a.size(), m = (int)b.size();

	int ok = 1, l = 0, r, l_ = 0, r_;
	for (; l < n and l_ < m and ok; l = r, l_ = r_) {

		r = l + 1;
		while (r < n and a[l] == a[r]) {
			r++;
		}

		r_ = l_ + 1;
		while (r_ < m and b[l_] == b[r_]) {
			r_++;
		}

		int ta = r - l, tb = r_ - l_;
		//cout << ta << ' ' << tb << endl;
		ok &= a[l] == b[l_] and (tb >= ta and tb <= 2 * ta);
	}

	ok &= !(l < n or l_ < m);
	cout << (ok ? "YES" : "NO") << endl;

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
