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

int main()
{
    _;

	int n, m, D; cin >> n >> m >> D;

	vector<vector<char>> M(n, vector<char>(m));
	vector<ii> livre;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			if (M[i][j] == '.') {
				livre.emplace_back(i, j);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < (int)livre.size(); i++) {
		for (int j = i + 1; j < (int)livre.size(); j++) {
			ii a = livre[i], b = livre[j];

			int agr = 0;
			for (int i = 0; i < (int)livre.size(); i++) {
				ii c = livre[i];
				int da = abs(c.f - a.f) + abs(c.s - a.s);
				int db = abs(c.f - b.f) + abs(c.s - b.s);
				agr += min(da, db) <= D;
			}
			res = max(res, agr);
		}
	}
   	cout << res << endl; 

    return(0);
}
