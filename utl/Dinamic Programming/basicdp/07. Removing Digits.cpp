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

vector<int> numeros(int ni) {
    vector<int> res;
    if (ni == 0) {
        res.push_back(0);
        return res;
    }
    while (ni) {
        res.push_back(ni % 10);
        ni /= 10;
    }
    return res;
}
int main()
{
    _;

	int n; cin >> n;
	vector<int> dp(n + 1, INF); // dp[i]: quantidade de mudancas para chegar em i;

	dp[n] = 0;
	for (int i = n; i >= 0; i--) {
		for (int j : numeros(i)) {
			if (i - j < 0) continue;
			dp[i - j] = min(dp[i - j], dp[i] + 1);
		}
	}

	cout << dp[0] << endl;
    
    return(0);
}
