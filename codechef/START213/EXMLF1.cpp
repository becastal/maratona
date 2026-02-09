#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	int mx = -1, p = -1;
	for (int i = 0, d, t; i < n; i++) {
		cin >> d >> t;

		if (mx < d / t) {
			mx = d / t;
			p = i + 1;
		}
	}
	cout << p << endl;

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

