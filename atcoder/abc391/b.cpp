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

	int n, m; cin >> n >> m;
	vector a(n, vector<char>(n)), b(m, vector<char>(m));
	for (auto& i : a) for (auto& j : i) cin >> j;
	for (auto& i : b) for (auto& j : i) cin >> j;

	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			int ok = 1;
			for (int ii = 0; ii < m; ii++) {
				for (int jj = 0; jj < m; jj++) {
					ok &= a[i+ii][j+jj]	== b[ii][jj];
				}
			}

			if (ok) return cout << i + 1 << ' ' << j+1 << endl, 0;
		}
	}
    
    return(0);
}
