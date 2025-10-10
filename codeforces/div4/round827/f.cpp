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

void solve() {
	int q; cin >> q;

	ll ca = 1, cb = 1;
	int outroa = 0, outrob = 0;
	for (int i = 0, tp, k; i < q; i++) {
		cin >> tp >> k;
		string s; cin >> s;

		if (tp == 1) {
			for (char c : s) {
				if (c != 'a') outroa = 1;
				ca += k;
			}
		} else {
			for (char c : s) {
				if (c != 'a') outrob = 1;
				cb += k;
			}
		}

		if (outrob) {
			cout << "YES" << endl;
		} else if (!outroa and ca < cb) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int main()
{
    _;

   	int t; cin >> t;
	while (t--) {
		solve();
	}
		
    return(0);
}
