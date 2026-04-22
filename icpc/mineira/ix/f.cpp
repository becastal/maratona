#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int m; cin >> m;
	string S; cin >> S;

	int mn = 0, mx = 0, p = 0;
	for (char c : S) {
		if (c == 'D') p += m;
		else p -= m;
		mn = min(mn, p);
		mx = max(mx, p);
	}
	cout << (mx - mn >= 360 ? 'S' : 'N') << endl;

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
