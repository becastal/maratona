include <bits/stdc++.h>
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
 
	int n, m; cin >> n >> m;
	ii a, b;
	vector<vector<char>> mp(n, vector<char>(m));
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'A') a = ii(i, j);
			if (mp[i][j] == 'B') b = ii(i, j);
		}
	}
	vector<vector<int>> d(n, vector<int>(m, -1));
	vector<vector<ii>> pai(n, vector<ii>(m, {-1, -1}));
	vector<vector<char>> cam(n, vector<char>(m, -1));
 
	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	vector<char> trad = {'U', 'L', 'D', 'R'};
 
	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and d[i][j] == -1 and mp[i][j] != '#';
	};
	auto bfs = [&]() {
		queue<ii> q; q.emplace(a.f, a.s);
		d[a.f][a.s] = 0;
 
		while (!q.empty()) {
			auto [ui, uj] = q.front(); q.pop();
 
			for (int i = 0; i < 4; i++) {
				ii mov = movs[i];
				int vi = ui + mov.f, vj = uj + mov.s;
				if (!valido(vi, vj)) continue;
 
				
				q.emplace(vi, vj);
				d[vi][vj] = d[ui][uj] + 1;
				pai[vi][vj] = ii(ui, uj);
				cam[vi][vj] = trad[i];
			}
		}
	};
	bfs();
 
	if (d[b.f][b.s] == -1) return cout << "NO" << endl, 0;
 
	cout << "YES" << endl << d[b.f][b.s] << endl;
	ii p = b;
	string res = "";
	while (p.f != -1) {
		res += cam[p.f][p.s];
		p = pai[p.f][p.s];
	}
	res.pop_back();
	reverse(res.begin(), res.end());
	cout << res << endl;
    
    return(0);
}
