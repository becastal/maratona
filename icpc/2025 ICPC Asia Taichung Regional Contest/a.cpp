#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int a, b, c; cin >> a >> b >> c;
	int mx = max({a, b, c}), mn = min({a, b, c});

	if (mx - mn >= 10) return cout << "check again" << endl, 0;
	cout << "final " << a + b + c - mx - mn << endl;

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

