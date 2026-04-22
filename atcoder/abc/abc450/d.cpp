#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		i %= k;
		cout << i << ' ';
	}
	cout << endl;

	int mx = *max_element(all(A));
	int mn = *min_element(all(A));
	cout << min(mx - mn + 1, (mn - mx + 1 + k) % k) << endl;

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

