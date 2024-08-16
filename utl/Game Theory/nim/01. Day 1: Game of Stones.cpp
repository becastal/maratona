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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> dp(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			for (int j : {2, 3, 5}) {
				if (i - j < 0) continue;
				if (!dp[i - j]) dp[i] = 1;
			}
		}

		cout << (dp[n] ? "First" : "Second") << endl;
	}
    
    return(0);
}
