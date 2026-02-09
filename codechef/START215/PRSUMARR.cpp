#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	if (n == 1) return cout << 1 << endl, 0;

	int res = 0;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			res++;
			n /= i;
		}
	}
	res += n != 1;
	cout << min(res, 3) << endl;

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

