#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dirs = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

const vector<char> Dirsc = {
	'R',
	'D',
	'L',
	'U'
};

int solve() {
	int n, m; cin >> n >> m;
	vector A(n, vector<char>(m));

	int ini = -1, inj = -1;
	int outi = -1, outj = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			auto& c = A[i][j];
			cin >> c;
			
			if (c == 'S') {
				ini = i, inj = j;	
			} else if (c == 'G') {
				outi = i, outj = j;	
			}
		}
	}

	vector Pai(n, vector(m, vector<tuple<int, int, int>>(4)));
	vector Vis(n, vector(m, vector<int>(4)));
	function<void(int, int, int)> dfs = [&](int ui, int uj, int udir) {
		Vis[ui][uj][udir] = 1;

		for (int vdir = 0; vdir < 4; vdir++) {
			if (A[ui][uj] == 'o' and vdir != udir) continue;
			if (A[ui][uj] == 'x' and vdir == udir) continue;
			auto [di, dj] = Dirs[vdir];
			int vi = ui + di, vj = uj + dj;
			if (vi < 0 or vj < 0 or vi >= n or vj >= m or A[vi][vj] == '#' or Vis[vi][vj][vdir]) continue;
			Pai[vi][vj][vdir] = tuple<int, int, int>(ui, uj, udir);
			dfs(vi, vj, vdir);
		}
	};

	for (int indir = 0; indir < 4; indir++) if (!Vis[ini][inj][indir]) {
		dfs(ini, inj, indir);
	}

	for (int outdir = 0; outdir < 4; outdir++) if (Vis[outi][outj][outdir]) {
		cout << "Yes" << endl;
		string Res = "";

		for (int ui = outi, uj = outj, udir = outdir; 
			ui != ini or uj != inj;
			tie(ui, uj, udir) = Pai[ui][uj][udir]) {
			Res.push_back(Dirsc[udir]);		
		}
		reverse(all(Res));
		cout << Res << endl;
		
		return 0;
	}
	cout << "No" << endl;

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

