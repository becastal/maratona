#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	ll n, m, k; cin >> n >> m >> k;
	
	if (m < n-1 or m > n * (n-1) / 2) return cout << "NO" << endl, 0;

	if (n == 1) return cout << (k > 1 ? "YES" : "NO") << endl, 0;

	if (m == n * (n-1) / 2) return cout << (k > 2 ? "YES" : "NO") << endl, 0;

	cout << (k > 3 ? "YES" : "NO") << endl;
		
	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
