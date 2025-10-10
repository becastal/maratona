#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

ll dp[20][2][2][11][11];
int solve() {
	ll l, r; cin >> l >> r;

	auto calc = [](ll x) {
		string S = to_string(x);
		int n = S.size();

		memset(dp, -1, sizeof(dp));
		function<ll(int, int, int, int, int)> f = [&](int pos, int tight, int zeroE, int pri, int ult) -> ll {
			if (pos == n) return ll(pri == ult);

			auto& res = dp[pos][tight][zeroE][pri][ult];
			if (res != -1) return res;

			res = 0;
			int teto = tight ? S[pos] - '0' : 9;
			for (int i = 0; i <= teto; i++) {
				int zeroE_ = zeroE and (i == 0);

				res += f(pos + 1,
						tight and (i == teto),
						zeroE and (i == 0),
						(!zeroE_ and pri == 10 ? i : pri),
						(!zeroE_ ? i : 0));
			}
			return res;
		};

		return f(0, 1, 1, 10, 10);
	};

	cout << calc(r) - calc(l-1) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
