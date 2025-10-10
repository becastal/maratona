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

vector<int> DP(501, INF);
int a, b, c, d, e, f;
void solve() {
	vector<int> v;
	double X; cin >> X;
	int x = round(X*100.0);

	for (int i = 0; i < a; i++) v.push_back(5);
	for (int i = 0; i < b; i++) v.push_back(10);
	for (int i = 0; i < c; i++) v.push_back(20);
	for (int i = 0; i < d; i++) v.push_back(50);
	for (int i = 0; i < e; i++) v.push_back(100);
	for (int i = 0; i < f; i++) v.push_back(200);

	vector<int> dp(501, INF);
	dp[0] = 0;

	for (int i : v) {
		for (int j = 500; j >= i; j--) {
			dp[j] = min(dp[j], dp[j-i] + 1);
		}
	}

	int res = INF;
	for (int i = x; i <= 500; i += 5) {
		if (dp[i] == INF) continue;
		
		int falta = i - x;
		res = min(res, dp[i] + DP[falta]);
	}

	cout << setw(3) << res << endl;
}

int main()
{
    _;

	DP[0] = 0;
	for (int i : {5, 10, 20, 50, 100, 200}) {
		for (int j = i; j <= 500; j++) {
			DP[j] = min(DP[j], DP[j-i] + 1);
		}
	}

	// knp pras minhas moedas e depois coin change pro troco.
	while (cin >> a >> b >> c >> d >> e >> f and (a or b or c or d or e or f)) {
		solve();
	}
	
    
    return(0);
}
