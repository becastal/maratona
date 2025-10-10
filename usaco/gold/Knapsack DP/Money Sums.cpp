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

	int n, s = 0; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i, s += i;

	vector dp(n+1, vector<int>(s+1, 0));

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = dp[i-1][j];
			int sobra = j - v[i-1];
			if (sobra >= 0) {
				dp[i][j] |= dp[i-1][sobra];
			}
		}
	}

	vector<int> res;
	for (int i = 1; i <= s; i++) {
		if (dp[n][i]) res.push_back(i);	
	}

	cout << (int)res.size() << endl;
	for (int i : res) cout << i << ' '; cout << endl;

    return(0);
}
