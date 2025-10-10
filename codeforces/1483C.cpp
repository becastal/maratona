#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> H(n), B(n);
	for (int& i : H) cin >> i;
	for (int& i : B) cin >> i;
	H.insert(H.begin(), 0);
	B.insert(B.begin(), 0);


//	for (int i = 1; i <= n; i++) {
//		int mn = H[i-1], mnp = i-1;
//		for (int j = i; j >= 1; j--) {
//			if (mn > H[j-1]) {
//				mn = H[j-1];
//				mnp = j-1;
//			}
//			dp[i] = max(dp[i], dp[j-1] + B[mnp]);
//		}
//	}
//	cout << dp[n] << endl;

	vector<ll> dp(n+1, -LINF);
	stack<array<ll, 2>> S;
	for (int i = 1; i <= n; i++) {
		ll agr = dp[i-1];
		while (S.size() and H[S.top()[0]] >= H[i]) {
			agr = max(agr, S.top()[1]);
			S.pop();
		}
		dp[i] = max((S.empty() ? B[i] : dp[S.top()[0]]), agr + B[i]);
		S.push({i, agr});
	}
	cout << dp[n] << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
