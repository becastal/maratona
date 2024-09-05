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

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	// achar a menor binary tree que representa essas unioes de adjascentes.
	// se comporta igual a uma segtree sum inclusive.
	// dp[l][r]: o minimo que custa pra combinar um intervalo de [l. r]
	vector<ll> pref(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + v[i];
	}
	vector<vector<ll>> dp(n, vector<ll> (n, LINF));
	
	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) {
				dp[l][r] = 0;
			} else {
				for (int i = l; i <= r - 1; i++) {
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + pref[r + 1] - pref[l]);
				}
			}
		}
	}

	cout << dp[0][n - 1] << endl;
    
    return(0);
}
