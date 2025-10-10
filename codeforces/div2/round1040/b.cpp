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

int dp[1010];
int solve() {
	int n, s; cin >> n >> s;
	vector<int> A(n), F(3, 0);
	for (int& i : A) cin >> i, F[i]++;

	int soma = accumulate(all(A), 0);
	if (s < soma) {
		for (int i : A) cout << i << ' '; cout << endl;
		return 0;
	} else if (s == soma) {
		return cout << -1 << endl, 0;
	} else {
		int f = s - soma;

		if (f == 1) {
			while (F[0]--) cout << 0 << ' ';	
			while (F[2]--) cout << 2 << ' ';	
			while (F[1]--) cout << 1 << ' ';
			cout << endl;
		} else return cout << -1 << endl, 0;
	}

	return(0);
}

int main()
{
    _;

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;	
	for (int i = 2; i < 1010; i++) {
		for (int j : {2, 3}) {
			dp[i] |= dp[i-j];		
		}
	}
	//for (int i = 0; i <= 20; i++) {
	//	cout << i << ": " << dp[i] << endl;
	//}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
