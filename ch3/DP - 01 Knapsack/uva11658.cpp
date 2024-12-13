#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int n, x;
	while (cin >> n >> x and n and x) {
		vector<int> v;
		int X;

		for (int i = 0; i < n; i++) {
			double vi; cin >> vi;

			if (x-1 == i) {
				X = int(round(vi * 100.0));
			} else {
				v.push_back(int(round(vi * 100.0)));
			}
		}
		n--;
		
		if (X > 5000) {
			cout << "100.00" << endl;
			continue;
		}

		const int tot = 10000;
		vector<int> dp(tot+1, 0);
		dp[0] = 1;

		for (int i : v) {
			for (int j = tot; j >= i; j--) {
				dp[j] |= dp[j-i];
			}
		}

		double res = 0;
		for (int i = 5000 - X; i <= tot - X; i++) {
			if (dp[i]) {
				res = max(res, 100.0 * X / (X + i));
			}
		}

		cout << fixed << setprecision(2) << res << endl;
	}
    
    return(0);
}
