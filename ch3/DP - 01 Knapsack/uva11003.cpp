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

int n;

void solve() {
	vector<int> w(n), cap(n);

	int W = 0, maxw = 0, maxcap = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> cap[i];
		maxw = max(maxw, w[i]);
		maxcap = max(maxcap, cap[i]);
	}

	vector<int> dp(maxw+maxcap+1, 0);
	for (int i = n-1; i >= 0; i--) {
		for (int j = cap[i]; j >= 0; j--) {
			if (dp[j]) dp[j + w[i]] = max(dp[j + w[i]], dp[j] + 1);
		}
		dp[w[i]] = max(dp[w[i]], 1);
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
    _;

	while (cin >> n and n) {
		solve();
	}
    
    return(0);
}
