#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> F(n+1, 0);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		F[x]++;
	}

	sort(rall(F));
	int res = 0;
	for (int i = 0, mn = INT_MAX; i < n; i++) {
		mn = min(mn, F[i]);
		res = max(res, mn * (i + 1));
	}
	cout << res << endl;

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

