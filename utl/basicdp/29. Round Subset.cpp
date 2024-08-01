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
typedef pair<int, int> ii;

int main()
{
    _;

	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n); // # 2s, # 5s;
	for (int i = 0; i < n; i++) {
		ll vi; cin >> vi;
		while (vi & 1 ^ 1) {
			vi /= 2, v[i].f++;
		}
		while (vi % 5 == 0) {
			vi /= 5, v[i].s++;
		}
	}

	// a quantidade de zeros que um numero pode me dar eh o min(.f, .s);
	// achar o subset de tamanho k que tenha o maior min(sigma(.f), sigma(.s));

	int maxm = 205 * 64;
	vector<vector<int>> dp(n + 1, vector<int> (maxm, -INF));

	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= 1; j--) {
			for (int l = v[i].f; l < maxm; l++) {
				dp[j][l] = max(dp[j][l], dp[j - 1][l - v[i].f] + v[i].s);
			}
		}
	}

	int res = 0;
	for (int i = 1; i < maxm; i++) {
		res = max(res, min(i, dp[k][i]));
	}
	cout << res << endl;

    return(0);
}
