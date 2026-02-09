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

	int n, x, y; 
	cin >> n >> x >> y; 

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	// o mais padrao seria:
	// dp[i][j][k]: a maior quantidade de pratos que da pra escolher, tal que a soma dos doces eh j e salg. eh k
	// mas isso eh mt pesado o(nxy), entao voce swapa o valor pela chave de j
	// dp[i][j][k]: a menor salgadez quando escolhendo k distindos valores dentre os i primeiros tal que a docura
	// eh exatamente j
	vector dp(n + 1, vector(n + 1, vector<int>(x + 1, INF)));

	auto minself = [](int& a, int b) {
		a = min(a, b);
	};

	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= x; k++) {
				minself(dp[i+1][j][k], dp[i][j][k]);
				if (k + a[i] <= x) {
					minself(dp[i+1][j+1][k + a[i]], dp[i][j][k] + b[i]);
				}
			}
		}
	}

	for (int i = n; i >= 0; i--) {
		for (int j = 0; j <= x; j++) {
			if (dp[n][i][j] <= y) {
				return cout << min(i + 1, n) << endl, 0;
			}
		}
	}
    
    return(0);
}
