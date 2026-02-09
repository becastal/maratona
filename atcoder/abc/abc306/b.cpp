#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef unsigned long long ll;
using namespace std;

int solve() {
	ll res = 0;
	for (int i = 0; i < 64; i++) {
		int x; cin >> x;
		if (x) res |= 1ULL << i;
	}
	cout << res << endl;

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

