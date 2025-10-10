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

void solve() {
	auto query = [&](int m1, int m2) {
		cout << "? " << m1 << ' ' << m2 << endl;
		int res; cin >> res;

		if (res == (m1+1)*(m2+1)) return 2;
		if (res == m1*(m2+1)) return 1;
		assert(res == m1*m2);
		return 0;
	};

	int l = 1, r = 999;

	while (r - l > 2) {
		int m1 = (2*l+r)/3;
		int m2 = (2*r+l)/3;
		int res = query(m1, m2);

		if (res == 2) {
			r = m1;
		} else if (res == 1) {
			l = m1;
			r = m2;
		} else {
			l = m2;
		}
	}

	if (r - l == 2) {
		cout << "? 1 " << l+1 << endl;	
		int res; cin >> res;

		if (res != l+1) {
			r = l+1;
		}
	}
	cout << "! " << r << endl;
}

int main()
{
    //_;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
