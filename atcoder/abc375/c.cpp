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
	vector v(n, vector<char>(n)), res(n, vector<char>(n));
	for (auto& l : v) for (auto& c : l) cin >> c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int d = min({i + 1, j + 1, n - i, n - j});
			int ni = i, nj = j;
			for (int k = 0; k < d % 4; k++) {
				int ti = nj, tj = n - 1 - ni;
				ni = ti, nj = tj;
			}
			res[ni][nj] = v[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
    
    return(0);
}
