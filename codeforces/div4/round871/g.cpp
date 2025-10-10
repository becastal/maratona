#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	const int MAX = 1e6+10;

	vector<vector<int>> cima(2*MAX);
	cima[2] = {1}, cima[3] = {1};

	vector<int> ult = {2, 3};
	for (int i = 4, agr = 3; i < MAX;) {
		vector<int> ulti;

		ulti.push_back(i);
		cima[i].push_back(ult[0]);
		for (int j = 1, l = 0; j < agr - 1; j++) {
			ulti.push_back(i+j);
			cima[i+j].push_back(ult[l]);	
			cima[i+j].push_back(ult[l+1]);	
			l++;
		}
		cima[i+agr-1].push_back(ult.back());
		ulti.push_back(i+agr-1);

		ult = ulti;
		i += agr;
		agr++;
	}


	vector<ll> dp(MAX, 0);
	dp[1] = 1, dp[2] = 5, dp[3] = 10;

	for (int i = 4; i < MAX; i++) {
		dp[i] = (ll)i * i;
		for (int j : cima[i]) {
			dp[i] += dp[j];	
		}
		if (cima[i].size() > 1) {
			for (int j : cima[cima[i][0]]) {
				for (int jj : cima[cima[i][1]]) {
					if (j == jj) {
						dp[i] -= dp[j];
					}
				}
			}
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}
    
    return(0);
}
