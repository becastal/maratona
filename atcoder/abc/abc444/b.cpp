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

	auto f = [](int a) {
		int res = 0;
		while (a) {
			res += a % 10;
			a /= 10;
		}
		return res;
	};

	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += f(i) == k;
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

