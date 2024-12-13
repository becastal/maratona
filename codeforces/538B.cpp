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

	vector<int> dez(8);
	dez[0] = 1;
	for (int i = 1; i < 8; i++) {
		dez[i] = dez[i-1]*10;
	}
	
	vector<int> quasi;
	for (int i = 1; i < (1 << 7); i++) {
		int agr = 0;
		for (int j = 0; j < 7; j++) {
			agr += !!(i & (1 << j)) * dez[j];
		}
		quasi.push_back(agr);
	}

	int n; cin >> n;
	vector<int> dp(n+1, INF), pai(n+1, -1);

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j : quasi) {
			if (i - j < 0) continue;	

			if (dp[i-j]+1<dp[i]) {
				dp[i] = dp[i-j]+1;
				pai[i] = i-j;
			}
		}
	}

	vector<int> res;
	int agr = n;
	do {
		res.push_back(agr - pai[agr]);
		agr = pai[agr];
	} while (agr != -1);
	res.pop_back();

	cout << dp[n] << endl;
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
