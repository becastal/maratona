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
	vector<string> v(8);
	for (auto& i : v) cin >> i;

	for (int i = 0; i < 8; i++) {
		int ok = 1;
		for (int j = 0; j < 8 and ok; j++) {
			ok &= (v[i][j] == 'R');
		}

		if (ok) return cout << 'R' << endl, 0;

		//int ok_ = 1;
		//for (int j = 0; j < 8 and ok_; j++) {
		//	ok_ &= (v[j][i] == 'R');
		//}

		//if (ok_) return cout << 'R' << endl, 0;
	}

	cout << 'B' << endl;
	return 0;
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
