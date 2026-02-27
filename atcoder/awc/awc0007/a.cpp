#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, mne = LLONG_MAX, res = 0; cin >> n >> m;
	for (int i = 0, e; i < n; i++) {
		cin >> e;
		mne = min(mne, e);
	}
	for (int i = 0, c; i < m; i++) {
		cin >> c;
		res += mne * c;
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
