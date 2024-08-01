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

const int mod = 1e9 + 7;

int main()
{
    _;
    
	int n; cin >> n;
	int k = (1 + n) * n / 2;

	// contar de quantas maneiras distintas consigo somar (k / 2);
	if (k & 1) return cout << 0 << endl, 0;
	vector<vector<int>> dp(n, vector<int>(k / 2 + 1, 0));	
	// dp[i][j]: quantidade de maneiras de somar j, tendo pego itens de 1 ate i;
	// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i], para considerar os casos que eu pego ou nao o item i;

	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k / 2; j++) {
			dp[i][j] = dp[i-1][j];
			int sobra = j - i;
			if (sobra >= 0) {
				dp[i][j] = (dp[i][j] + dp[i - 1][sobra]) % mod;
			}
		}
	}

	cout << dp[n - 1][k / 2] << endl;

    return(0);
}
