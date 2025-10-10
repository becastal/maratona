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
	setIO("snowboots");

	int n, b; cin >> n >> b;
	vector<int> f(n);
		for (int& i : f) cin >> i;

	vector<pair<int, int>> B(b);
	for (auto& [fi, di] : B) {
		cin >> fi >> di;
	}

	int res = n;
	vector<vector<int>> vis(n, vector<int>(b, 0));
	function<void(int, int)> dfs = [&](int i, int j) {
		//printf("(%d, %d)\n", i, j);
		vis[i][j] = 1;
		if (i == n-1) {
			res = min(res, j);
			return;
		}

		auto [fi, di] = B[j];
		for (int ii = i + 1; ii <= i + di and ii < n; ii++) {
			if (f[ii] <= fi and !vis[ii][j]) {
				dfs(ii, j);	
			}
		}

		for (int jj = j; jj < b; jj++) {
			if (f[i] <= B[jj].f and !vis[i][jj]) {
				dfs(i, jj);	
			}
		}
	};
	dfs(0, 0);

	cout << res << endl;

    return(0);
}
