#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int m, a, x, y; cin >> m >> a >> x >> y;
	double umquinto = 1.0 / 5;

	map<int, double> Memo;
	function<double(int)> f = [&](int n) {
		if (Memo.count(n)) return Memo[n];
		if (n == 0) return 0.0;

		Memo[n] = x + f(n / a);
		double soma = 6.0 * umquinto * y;

		for (int i = 2; i <= 6; i++) {
			soma += umquinto * f(n / i);
		}
		return Memo[n] = min(Memo[n], soma);
	};
	cout << fixed << setprecision(20);
	cout << f(m) << endl;

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

