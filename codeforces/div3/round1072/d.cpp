#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const ll MAX = 35;
ll C[MAX][MAX];

int solve() {
	int n, k; cin >> n >> k;

	//for (int i = 1; i <= n; i++) {
	//	int p = 32 - __builtin_clz(i) - 1 + __builtin_popcount(i);
	//	//cout << i << ": (" << 32 - __builtin_clz(i) << ' ' << __builtin_popcount(i) << ")\n";
	//	res += p > k;
	//}

	int res = 0;
	for (int t = 1; t < 32 - __builtin_clz(n); t++) {
		for (int x = 0; x < t; x++) if (t - 1 + x + 1 > k) {
			res += C[t-1][x];
		}
	}
	res += 32 - __builtin_clz(n) - 1 + __builtin_popcount(n) > k;
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	for (int i = 0; i < MAX ; i++){ 
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++){ 
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

