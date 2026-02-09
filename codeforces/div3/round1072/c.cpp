#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;

	int l = n, r = n, d = 0;
	for (int i = 0; i < 33; i++) {
		if (l <= k and k <= r) break;
		l = l / 2;
		r = r / 2 + (r & 1);
		d++;
	}
	if (k < l or k > r) return cout << -1 << endl, 0;
	cout << d << endl;

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

