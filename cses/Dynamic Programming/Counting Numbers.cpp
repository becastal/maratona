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

int solve() {
	ll a, b; cin >> a >> b;
	string A = to_string(a-1), B = to_string(b);

	auto calc = [](string S) {
		ll dp[20][2][2][11];
		memset(dp, -1, sizeof(dp));

		auto f = [&](auto&& f, int pos, int tight, int zeroE, int ult) -> ll {
			if (pos == S.size()) return 1;

			auto& res = dp[pos][tight][zeroE][ult];
			if (res != -1) return res;

			res = 0;
			int teto = tight ? S[pos] - '0' : 9;
			for (int i = 0; i <= teto; i++) {
				if (!(zeroE and i == 0) and i == ult) continue;

				int zeroE_ = zeroE and (i == 0);
				res += f(f, pos + 1,
						tight and (i == teto),
						zeroE_,
						zeroE_ ? ult : i);
			}
			return res;
		};

		return f(f, 0, 1, 1, 10);
	};
	cout << calc(B) - calc(A) << endl;

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
