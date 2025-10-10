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
 
	int n, x; cin >> n >> x;
	vector<int> v(n), dp(x + 1, INF); // dp[i]: min de moedas para chegar em i;
	for (int& i : v)  {
		cin >> i;
		if (i <= x) dp[i] = 1;
	}
 
	// bem parecido com coin combination, mas algum min na jogada.
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - v[j] < 0) continue;
			dp[i] = min(dp[i], dp[i - v[j]] + 1);
		}
	}
 
	cout << (dp[x] != INF ? dp[x] : -1) << endl;
    
    return(0);
}
