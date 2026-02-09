#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int V[2000];

map<int, int> memo;
signed solve(int n) {
	auto query = [&](int x) {
		if (memo.count(x)) return memo[x];
		cout << "? " << x << endl;
		int a; cin >> a;
		return memo[x] = a;
	};
//	auto query = [&](int x) {
//		return V[x];
//	};
	int a = query(1), c = query(n);

	int l = 2, r = n - 1, res = n-1;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (2 * query(m) >= (a + c)) {
			r = m - 1;
			res = m;
		} else {
			l = m + 1;
		}
	}

	int res_ = res; 
	double soma = -1e18;
	for (int i = -2; i <= +2; i++) if (res + i >= 2 and res + i <= n - 1) {
		int b = query(res + i);

		double agr = sqrt(abs(a - b)) + sqrt(abs(a - c)) + sqrt(abs(b - c));
		if (soma < agr) {
			soma = agr;
			res_ = res + i;
		}
	}

	cout << "! 1 " << res_ << ' ' << n << endl;		

	return(0);
}

signed main()
{
    //_;


	int t = 1, n; //cin >> t;

	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> V[i];
//	}

	while (t--) {
		solve(n);
	}
    
    return(0);
}
