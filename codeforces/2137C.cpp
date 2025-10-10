#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll a, b; cin >> a >> b;

	ll a_ = a, b_ = b;
	int c2a = 0, c2b = 0;
	while (a_ % 2 == 0) c2a++, a_ /= 2;
	while (b_ % 2 == 0) c2b++, b_ /= 2;
	
	if (a * b & 1) return cout << a * b + 1 << endl, 0;
	if ((b & 1) or (c2a + c2b == 1)) return cout << -1 << endl, 0;
	cout << (a * b) / 2 + 2 << endl;

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

