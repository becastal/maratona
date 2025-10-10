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

int S;

int solve(int n, vector<int>& v) {
	int tot = *max_element(v.begin(), v.end()) * S + 10;

	vector<vector<int>> dp(tot+1, vector<int>(S+1, 0));
	dp[0][0] = 1;

	for (int i : v) {
		for (int j = i; j <= tot; j++) {
			for (int k = 1; k <= S; k++) {
				dp[j][k] |= dp[j-i][k-1];
			}
		}
	}

	int res = 1, ok = 1;
	for (; res <= tot and ok; res++) {
		int oki = 0;
		for (int i = 1; i <= S; i++) {
			oki |= dp[res][i];
		}

		ok &= oki;
	}
	res -= 2;

	return res;
}

int main()
{
    _;

	while (cin >> S and S) {
		int n; cin >> n;
		vector<vector<int>> v(n);

		vector<tuple<int, int, vector<int>>> R;
		int res = 0, res_pos = 0;
		for (int i = 0; i < n; i++) {
			int ni; cin >> ni;	
			for (int j = 0; j < ni; j++) {
				int x; cin >> x;
				v[i].push_back(x);
			}

			reverse(v[i].begin(), v[i].end());
			R.emplace_back(-solve(ni, v[i]), v[i].size(), v[i]);
		}

		sort(R.begin(), R.end());
		auto [R0, R1, R2] = R[0];
		cout << "max coverage =" << setw(4) << -R0 << " :";
		reverse(R2.begin(), R2.end());
		for (int i : R2) cout << setw(3) << i; cout << endl;
	}
    
    return(0);
}
