#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

ll ruim(ll n) {
	vector<vector<vector<ll>>> dp(20, vector<vector<ll>>(2, vector<ll>(11, -1)));
	string s = to_string(n);

	function<ll(int, int, int)> f = [&](int pos, int t, int ult) -> ll {
		if (pos == (int)s.size()) return 1;
		if (dp[pos][t][ult] != -1) return dp[pos][t][ult];

		ll res = 0;
		int lim = t ? (s[pos]-'0') : 9;

		for (int d = 0; d <= lim; d++) {
			if (d == 4) continue;
			if (ult == 1 and d == 3) continue;

			int nt = (t and (d == lim) ? 1 : 0);
			res += f(pos +  1, nt, d);
		}

		return dp[pos][t][ult] = res;
	};

	return (n + 1) - f(0, 1, 10) ;
}

void solve(ll n) {
	ll dif = ruim(n);
	while (dif) {
		ll ni = n + dif;
		dif = ruim(ni) - ruim(n);
		n = ni;
	}
	cout << n << endl;
}

int main()
{
    _;

	ll n;
	while (cin >> n) {
		solve(n);
	}
    
    return(0);
}
