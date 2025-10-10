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

void solve(int n, int x) {
	vector<int> v(n); 
	int tot = 0;
	for (int& i : v) cin >> i, tot += i;

	vector<vector<bool>> dp(n+1, vector<bool>(2*tot+1, 0));
	dp[0][tot] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = -tot; j <= tot; j++) {
			if (dp[i-1][j+tot]) {
				if (j + v[i-1] <= tot) dp[i][j + v[i-1] + tot] = 1;
				if (j - v[i-1] >= -tot) dp[i][j - v[i-1] + tot] = 1;
			}
		}
	}

	if (x < -tot or x > tot or !dp[n][x+tot]) {
		cout << "*" << endl;
		return;
	}
	
	vector<int> agr(2*tot+1, 0);
	agr[x+tot] = 1;

	string res = "";
	for (int i = n; i >= 1; i--) {
		int pos = 0, neg = 0;

		vector<int> agr_i(2*tot+1, 0);
		for (int j = -tot; j <= tot; j++) {
			if (j + v[i-1] <= tot and dp[i-1][j + v[i-1] + tot] and agr[j + tot]) {
				neg = 1;
				agr_i[j + v[i-1] + tot] = 1;
			}

			if (j - v[i-1] >= -tot and dp[i-1][j - v[i-1] + tot] and agr[j + tot]) {
				pos = 1;
				agr_i[j - v[i-1] + tot] = 1;
			}
		}
		agr = move(agr_i);

		if (pos and neg) res.push_back('?');
		else res.push_back(pos ? '+' : '-');
	}
	reverse(res.begin(), res.end());

	cout << res << endl;
}

int main()
{
    _;

	int n, x;
	while (cin >> n >> x and n) {
		solve(n, x);
	}
    
    return(0);
}
