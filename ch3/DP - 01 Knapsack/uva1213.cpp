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

const int maxn = 1140, maxk = 15;

int divi[maxn];
vector<int> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int main()
{
    _;

	crivo(maxn-1);

	vector<vector<int>> dp(maxk+1, vector<int>(maxn+1, 0));
	dp[0][0] = 1;

	for (int i : primes) {
		for (int j = maxk; j >= 1; j--) {
			for (int k = maxn; k >= i; k--) {
				dp[j][k] += dp[j-1][k-i];
			}
		}
	}

	int n, k; 
	while (cin >> n >> k and n and k) {
		cout << dp[k][n] << endl;
	}
    
    return(0);
}
