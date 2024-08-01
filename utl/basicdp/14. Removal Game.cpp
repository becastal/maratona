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
	ll soma = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i, soma += i;
	// se a soma de p1 e p2 eh o total de v, entao p1 quer fazer s1 - s2 grande e p2 quer fazer pequeno.
	// dp[l][r]: s1 - s2 se o jogo for jogado em [l, r];
	
	vector<vector<ll>> dp(n, vector<ll>(n));
	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) {
				dp[l][r] = v[l];
			} else {
				dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
			}
		}
	}

	cout << (soma + dp[0][n - 1]) / 2 << endl;
    
    return(0);
}
