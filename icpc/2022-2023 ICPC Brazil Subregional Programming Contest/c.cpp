#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2e3+10;
int Vis[MAX][MAX], B[MAX][MAX];
const vector<array<int, 2>> Movs = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int dfs(int ini, int inj) {
	stack<array<int, 2>> S; S.push({ini, inj});
	Vis[ini][inj] = 1;

	int cont = 0;
	while (S.size()) {
		auto [ui, uj] = S.top(); S.pop();
		cont += ui & uj & 1;
		
		for (auto [di, dj] : Movs) {
			int vi = ui + di, vj = uj + dj;
			if (vi < 0 or vj < 0 or vi >= MAX or vj >= MAX or Vis[vi][vj] or B[vi][vj]) continue;
			Vis[vi][vj] = 1;
			S.push({vi, vj});
		}
	}
	return cont;
}

void update(array<int, 2>& a, array<int, 2>& b) {
	auto [xa, ya] = a;	
	auto [xb, yb] = b;	
	xa *= 2, ya *= 2;
	xb *= 2, yb *= 2;

	if (xa == xb and ya > yb) {
		swap(xa, xb);
		swap(ya, yb);
	}
	if (ya == yb and xa > xb) {
		swap(xa, xb);
		swap(ya, yb);
	}

	B[xa][ya]++;
	B[xb+1][ya]--;
	B[xa][yb+1]--;
	B[xb+1][yb+1]++;
}

int solve() {
	int n; cin >> n;

	vector<array<int, 2>> A(n + 1);
	for (auto& [x, y] : A) {
		cin >> x >> y;
	}

	for (int i = 0; i < n; i++) {
		update(A[i], A[i + 1]);
	}

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			B[i][j] += B[i][j-1] + B[i-1][j] - B[i-1][j-1];
		}
	}

	int res = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) if (!Vis[i][j] and !B[i][j]) {
			int agr = dfs(i, j);	

			if (i and j) {
				res = max(res, agr);
			}
		}
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

