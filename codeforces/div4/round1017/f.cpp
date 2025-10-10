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

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<int> v(k);
	vector<vector<int>> res(n, vector<int>(m));
	iota(v.begin(), v.end(), 1);
	
    for (int i = 0; i < n * m / k; i++) {
        int pos = i * k, ii = (m % k == 0 ? (pos / m) % k : 0);
        for (int j = 0; j < k; j++, ii++, ii %= k, pos++) {
            res[pos / m][pos % m] = v[ii];
        }
    }

	vector<pair<int, int>> movs = {
		{1, 0},
		{0, 1},
		{-1, 0},
		{0, -1}
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j] << ' ';
			for (auto mov : movs) {
				int ii = i + mov.f, jj = j + mov.s;
				if (ii < 0 or jj < 0 or ii >= n or jj >= m) continue;
				assert(res[ii][jj] != res[i][j]);
			}
		}
		cout << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
