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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int n; cin >> n;
	vector<int> dp(n+1, 0);
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6 and j <= i; j++) {
			dp[i] = (dp[i] + dp[i-j]) % mod;
		}
	}
	cout << dp[n] << endl;

    return(0);
}
