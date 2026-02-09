#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, h, x; cin >> n >> h >> x;

	for (int i = 0, a; i < n; i++) {
		cin >> a;
		if (h + a >= x) return cout << i + 1 << endl, 0;
	}
	assert(0);

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

