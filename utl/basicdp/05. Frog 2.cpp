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

	int n, k; cin >> n >> k;
	vector<int> h(n);
	for (int& i : h) cin >> i;

	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (i + j >= n) return;
			dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
		}
	}
	cout << dp.back() << endl;
    
    return(0);
}
