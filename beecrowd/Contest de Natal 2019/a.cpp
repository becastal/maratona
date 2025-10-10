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
typedef pair<int, int> ii;

void solve(int n, int m, int p) {
	vector<ii> P(p);
	
	vector<vector<int>> M(n, vector<int>(m, 0));
	for (auto& [x, y] : P) {
		cin >> x >> y;
		M[--x][--y]++;	
	}

	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << M[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	int res = 1;
	for (int i = 0; i < p and res; i++) {
		for (int j = i + 1; j < p and res; j++) {
			if ((P[i].f == P[j].f) or (P[i].s == P[j].s)) continue;

			int soma = 0;
			for (int ii = min(P[i].f, P[j].f); ii <= max(P[i].f, P[j].f); ii++) {
				for (int jj = min(P[i].s, P[j].s); jj <= max(P[i].s, P[j].s); jj++) {
					soma += M[ii][jj];
				}
			}

			res &= (soma > 2);
		}
	}
	
	cout << (res ? 'Y' : 'N') << endl;
}

int main()
{
    _;

	int n, m, p;
	while (cin >> n >> m >> p) {
		solve(n, m, p);
	}
    
    return(0);
}
