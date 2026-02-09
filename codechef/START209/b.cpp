#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int x, y; cin >> x >> y;

	int se = 0, so = 0;
	for (int i = x; i <= y; i += x) {
		if (i & 1) {
			so += i;
		} else {
			se += i;
		}
	}
	cout << (se >= so ? "YES" : "NO") << endl;

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

