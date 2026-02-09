#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int s, k, m; cin >> s >> k >> m;

	if (s <= k) return cout << max(0, s - m % k) << endl, 0;
	cout << (((m % (2 * k)) < k) ? s - m % k : k - m % k) << endl;

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

