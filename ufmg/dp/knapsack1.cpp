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
	vector<int> peso(n), valor(n);

	for (int i = 0; i < n; i++)
		cin >> peso[i] >> valor[i];

	vector<ll> dp(w + 1, 0);
	// dp[i] -> maximo de valor que consigo com peso i;

	for (int i = 0; i < n; i++)
		for (int agr = w - peso[i]; agr >= 0; agr--)
			dp[agr + peso[i]] = max(dp[agr + peso[i]], dp[agr] + valor[i]);
			// itera por todos os possiveis pesos de ter pego ou nao o item i e adiciona o valor caso seja melhor

	ll res = 0;
	for (int i = 0; i <= w; i++)
		res = max(res, dp[i]);

	cout << res << endl;
    
    return(0);
}
