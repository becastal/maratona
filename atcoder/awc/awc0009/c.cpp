#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, t, k, mn = LLONG_MAX, res = 0; cin >> n >> t >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		mn = min(mn, i);
	}

	for (int i : A) {
		res += i - (mn - 1) <= t + k;	
	}
	cout << res << endl;

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

