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
	ll n; cin >> n;

	auto da = [&](ll x) {
		string S = to_string(x);

		ll dp[20][2][2][20];
		for (int dig = 0; dig <= 9; dig++) {
			memset(dp, -1, sizeof(dp));

			auto f = [&](auto&& f, int pos, int tight, int zeroE, int cont) -> ll {
				if (pos == S.size()) return cont;
				
				auto& res = dp[pos][tight][zeroE][cont];
				if (res != -1) return res;

				res = 0;
				int teto = tight ? S[pos] - '0' : 9;
				for (int i = 0; i <= teto; i++) {
					res += f(f,
							pos + 1,
							tight and (i == teto),
							zeroE and (i == 0),
							cont + (i == dig and !(zeroE and i == 0)));
				}
				return res;
			};

			if (f(f, 0, 1, 1, 0) > n) return 0;
		}
		return 1;
	};
	//dbg(da(13));

	ll l = 0, r = (ll)1e18+10, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			res = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	cout << res << endl;

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
