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

    int t, n; 
    cin >> t >> n;
    vector<int> v(n);
	multiset<int> ms;
    for (int& i : v) cin >> i, ms.insert(i);
    
    vector dp(n+1, vector<int>(t+1, INF)), pai(n+1, vector<int>(t+1, -1));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i-1][j];
            pai[i][j] = -1;

            int ult = j - v[i-1];
            if (ult >= 0 and dp[i-1][ult] + 1 < dp[i][j]) {
                dp[i][j] = dp[i-1][ult] + 1;
                pai[i][j] = i-1;
            }
        }
    }

	vector<int> usados;
	int j = t;
	while (dp[n][j] == INF) {
		j--;
	}

	for (int i = n; i > 0 and j > 0; i--) {
		if (pai[i][j] != -1) {
			usados.push_back(v[pai[i][j]]);
			j -= v[pai[i][j]];
		}
	}

	for (int i : usados) cout << i << ' '; cout << endl;

    return 0;
}

