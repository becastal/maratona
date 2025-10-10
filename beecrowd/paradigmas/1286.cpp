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

void solve(int n) {
	int P; cin >> P;
	vector<int> t(n), v(n);

	int T = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> v[i];
		T += t[i]; 
	}

	vector<int> dp(T+1, INF);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = T; j >= t[i]; j--) {
			dp[j] = min(dp[j], dp[j-t[i]] + v[i]);
		}
	}

	int res = 0;
	for (int i = 0; i <= T; i++) {
		if (dp[i] <= P) res = i;
	}
	cout << res << " min." << endl;
}

int main()
{
    _;

	int n;
	while (cin >> n and n) {
		solve(n);
	}
    
    return(0);
}
