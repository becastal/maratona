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

	int cont = 1;
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		vector<double> dp(101, 9e9);

		double un; ss >> un;
		dp[0] = 0.0, dp[1] = un;
		
		int m; ss >> m;
		map<int, double> M = {{1, un}};
		for (int i = 0; i < m; i++) {
			getline(cin, s); stringstream ss(s);
			int n; ss >> n;
			double di; ss >> di;
			if (M.count(n)) M[n] = min(M[n], di);
			else M[n] = di;
		}
		
		for (auto [i, pi] : M) {
			for (int j = 100; j >= i; j--) {
				dp[j] = min(dp[j], dp[j-i] + pi);
			}
		}

		for (int i = 99; i >= 0; i--) {
			dp[i] = min(dp[i], dp[i+1]);
		}
		
		cout << "Case " << cont++ << ":" << endl;
		getline(cin, s); ss.clear(); ss.str(s);
		int ni; 
		while (ss >> ni) {
			cout << "Buy " << ni << " for $" << fixed << setprecision(2) << dp[ni] << endl;
		}
	}
    
    return(0);
}
