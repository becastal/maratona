#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	
	int mnx = INT_MAX, mny = INT_MAX;
	int mxx = INT_MIN, mxy = INT_MIN;

	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		mnx = min(mnx, x);
		mny = min(mny, y);
		mxx = max(mxx, x);
		mxy = max(mxy, y);
	}

	//cout << mnx << ' ' << mxx << endl;

	cout << 1LL * 2 * ((mxx - mnx) + (mxy - mny)) + 8 << endl;

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

