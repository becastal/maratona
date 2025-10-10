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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("lazy");

	int n, k; cin >> n >> k;
	int m = 2*n-1;
	vector<vector<int>> v(n, vector<int>(n)), v_(m, vector<int>(m, -1));
	vector<vector<ll>> pre(m+1, vector<ll>(m+1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			v_[i+j][i-j+(n-1)] = v[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] = max(0, v_[i-1][j-1]) + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}

	if (k >= m) return cout << pre[m][m] << endl, 0;

	k <<= 1;
	ll res = 0;
	for (int i = 1; i <= m - k; i++) {
		for (int j = 1; j <= m - k; j++) {
			res = max(res, pre[i+k][j+k] - pre[i-1][j+k] - pre[i+k][j-1] + pre[i-1][j-1]);
		}
	}
	cout << res << endl;

    return(0);
}
