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
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	vector<int> ord(n); 
	iota(ord.begin(), ord.end(), 0);

	sort(ord.begin(), ord.end(), [&](int i, int j) { return B[i] * (A[j] - 1) > B[j] * (A[i] - 1); });
	vector<ll> dp(k+1, -LINF);

	dp[0] = 1;
	for (int i : ord) {
		auto dpi = dp;
		for (int j = 0; j < k; j++) {
			if (dp[j] == -LINF) continue;
			dpi[j+1] = max(dpi[j+1], dp[j] * A[i] + B[i]);
		}
		dp = move(dpi);
	}
	cout << dp[k] << endl;
    
    return(0);
}
