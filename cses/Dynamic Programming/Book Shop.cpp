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
	vector<int> h(n), s(n), dp(x + 1, 0);
	for (int& i : h) cin >> i;
	for (int& i : s) cin >> i;
 
	for (int i = 0; i < n; i++) {
		for (int j = x - h[i]; j >= 0; j--) {
			dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
		}
	}
 
	cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return(0);
}
