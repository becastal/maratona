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

	ll n, k; cin >> n >> k;
	string s; cin >> s;

	vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
	dp[0][0] = 1;
	vector<ll> ult(26, -1);

	for (ll i = 1; i <= n; i++) {
		dp[i] = dp[i-1];

		for (ll j = 1; j <= n; j++) {
			ll agr = dp[i-1][j-1];
			if (ult[s[i-1]-'a'] != -1) {
				agr -= dp[ult[s[i-1]-'a'] - 1][j-1];
			}
			dp[i][j] += agr;
		}

		ult[s[i-1]-'a'] = i;
	}

	ll res = 0;
	for (ll i = n; i >= 0 and k > 0; i--) {
		ll usei = min(k, dp[n][i]);
		res += usei * (n - i);
		k -= usei;
	}
	cout << (k ? -1 : res) << endl;
    
    return(0);
}
