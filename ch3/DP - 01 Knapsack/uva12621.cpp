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

void solve() {
	int N, n, tot = 0; cin >> N >> n;

	vector<int> v(n);
	for (int& i : v) cin >> i, tot += i;

	vector<int> dp(tot+1, 0);
	dp[0] = 1;

	for (int i : v) {
		for (int j = tot; j >= i; j--) {
			dp[j] |= dp[j-i];
		}
	}

	if (tot < N) {
		cout << "NO SOLUTION" << endl;
		return;
	}

	int res = N, ok = 0;
	for (; !ok; res++) {
		ok |= dp[res];
	}

	cout << res-1 << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
