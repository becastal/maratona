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

	int n, tot = 0; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i, tot += i;

	vector<int> dp(tot+1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = tot; j >= v[i]; j--) {
			dp[j] |= dp[j-v[i]];
		}
	}

	int ok = 0;
	int i = tot;
	for (i; !ok and i >= 0; i--) {
		if (i % 10 and dp[i]) ok = 1;
	}

	cout << i+1 << endl;
    
    return(0);
}
