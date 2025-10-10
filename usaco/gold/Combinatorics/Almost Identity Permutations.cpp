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

int solve() {
	vector<ll> D = {1, 0, 1, 2, 9, 44};
	int n, k; cin >> n >> k;

	vector<vector<ll>> C(n + 1, vector<ll>(k + 1));
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}

	ll res = 0;
	for (int i = 0; i <= k; i++) {
		res += C[n][i] * D[i];
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
