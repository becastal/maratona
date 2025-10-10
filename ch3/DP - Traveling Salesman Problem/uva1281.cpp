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

void solve(int n, int m) {
	vector<vector<int>> d(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) d[i][i] = 0;

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		d[u][v] = d[v][u] = w;
	}

	for (int b = 0; b < n; b++) {
		for (int a = 0; a < n; a++) {
			for (int c = 0; c < n; c++) {
				d[a][c] = min(d[a][c], d[a][b] + d[b][c]);
			}
		}
	}

	
}

int main()
{
    _;

	int n, m; 
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}
