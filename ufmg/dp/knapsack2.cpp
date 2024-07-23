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

	int n, w;
    cin >> n >> w;
	vector<int> p(n), v(n);

	ll soma = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i] >> v[i];
		soma += v[i];
	}

	vector<ll> dp(soma + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int agr = soma - v[i]; agr >= 0; agr--)
			dp[agr + v[i]] = min(dp[agr + v[i]], dp[agr] + p[i]);		

	ll res = 0;
	for (int i = 0; i <= soma; i++)
		if (dp[i] <= w)
			res = max(res, (ll) i);

	cout << res << endl;

    return(0);
}
