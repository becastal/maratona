#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll n; cin >> n;

	int f = 0;
	while (n & 1 ^ 1) {
		f++;
		n >>= 1;
	}

	if (!f) return cout << 0 << endl, 0;
	cout << f / 2 << endl;

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

