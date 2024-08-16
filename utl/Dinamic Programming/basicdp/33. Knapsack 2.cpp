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

	int n, W, tot = 0; cin >> n >> W;
	vector<int> w(n), v(n);
   	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i], tot += v[i];

	// como w agora eh enorme, a dp eh encima do valor;
	// dp[i]: o minimo de peso que eu tenho que por pra criar uma mochila com valor i;

	vector<ll> dp(tot + 1, LINF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = tot - v[i]; j >= 0; j--) {
			dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
		}
	}

	int res = 0;
	for (int i = 0; i <= tot; i++)
		if (dp[i] <= W) 
			res = i;

	cout << res << endl;

    return(0);
}
