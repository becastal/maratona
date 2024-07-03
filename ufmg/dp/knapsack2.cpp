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

int n, w;
vector<int> p, v;
ll memo[100][100010];

ll dp(int i, int j)
{
	if (j < 0) return -INF;
	if (i == n) return 0;
	ll& at = memo[i][j];

	if (at != -1) return at;
	return at = max(dp(i + 1, j), dp(i + 1, j - p[i]) + v[i]);
}

int main()
{
    _;

    cin >> n >> w;
	p.resize(n), v.resize(n);
	memset(memo, -1, sizeof(memo));

	for (int i = 0; i < n; i++)
		cin >> p[i] >> v[i];

	cout << dp(0, w) << endl;

    return(0);
}
