#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, s, t, soma = 0; cin >> n >> s >> t;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		soma += x;
	}
	cout << (soma > 60 * (t - s) ? "No" : "Yes") << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

