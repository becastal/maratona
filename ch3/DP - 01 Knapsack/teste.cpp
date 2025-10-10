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

void solve(int n, int x) {
    vector<int> v(n);
    int tot = 0;
    for (int &i : v) {
        cin >> i;
        tot += abs(i);  // Sum of absolute values
    }

    // DP table: dp[i][s] where s is offset by tot
    vector<vector<int>> dp(n + 1, vector<int>(2 * tot + 1, 0));
    dp[0][tot] = 1;  // Sum 0 is possible with no elements

    for (int i = 1; i <= n; i++) {
        for (int j = -tot; j <= tot; j++) {
            if (dp[i - 1][j + tot]) {
                dp[i][j + v[i - 1] + tot] = 1;
                dp[i][j - v[i - 1] + tot] = 1;
            }
        }
    }

    if (x >= -tot && x <= tot && dp[n][x + tot]) {
        cout << "y" << endl;
    } else {
        cout << "n" << endl;
    }
}

int main() {
    _;

	
	int n, x; 
	while (cin >> n >> x) {
		solve(n, x);
	}


    return 0;
}
