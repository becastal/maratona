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
    
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<ll>> dp(n, vector<ll>(2));
	vector<vector<pair<int, int>>> pai(n, vector<pair<int, int>>(2));
	dp[0][0] = v[0];
	dp[0][1] = 2*v[0];
	pai[0][0] = {-1, -1}, pai[0][1] = {-1, -1};

	for (int i = 1; i < n; i++) {
		if (dp[i-1][0] > dp[i-1][1]) {
			dp[i][0] = v[i] + dp[i-1][0];
			pai[i][0] = {i-1, 0};
		} else {
			dp[i][0] = v[i] + dp[i-1][1];
			pai[i][0] = {i-1, 1};
		}

		if (2*v[i] + dp[i-1][0] > dp[i][0]) {
			dp[i][1] = 2*v[i] + dp[i-1][0];
			pai[i][1] = {i-1, 0};
		} else {
			pai[i][1] = pai[i][0];
		}
	}

	string res = "";
	pair<int, int> agr;
	if (dp[n-1][0] > dp[n-1][1]) {
		agr = {n-1, 0};
	} else {
		agr = {n-1, 1};
	}

	for (; agr != make_pair(-1, -1); agr = pai[agr.f][agr.s]) {
		res.push_back(agr.s ? 'M' : 'O');
	}
	reverse(res.begin(), res.end());

	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
	cout << res << endl;

    return(0);
}
