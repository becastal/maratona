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

	int tt; cin >> tt;
	while (tt--)
	{
		string a, b; cin >> a >> b;
		if (a.size() < b.size()) swap(a, b);

		vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));	
		for (int i = 0; i < a.size(); i++)
			dp[i][0] = dp[0][i] = i;

		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i] == b[j])
					dp[i + 1][j + 1] = dp[i][j];
				else
					dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
			}

		for (auto l : dp)
		{
			for (auto c : l)
				cerr << c << ' ';
			cerr << endl;
		}

		cout << dp[a.size()][b.size()] << endl;
	}
    
    return(0);
}
