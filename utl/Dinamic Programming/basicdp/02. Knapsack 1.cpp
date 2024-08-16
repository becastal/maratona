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

	int n, W; cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];

	vector<ll> dp(W + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = W - w[i]; j >= 0; j--) {
			dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return(0);
}
