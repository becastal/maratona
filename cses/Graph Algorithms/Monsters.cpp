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
 
	int n, m; cin >> n >> m;
	vector<ii> eles;
	ii eu, saida = ii(-1, -1);
 
	vector<vector<char>> mp(n, vector<char> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'A') eu = ii(i, j);
			if (mp[i][j] == 'M') eles.emplace_back(i, j);
		}
	}
	vector<vector<int>> d_eles(n, vector<int> (m, -1)), d_eu(n, vector<int> (m, -1));
	vector<ii> movs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	vector<char> trad = {'U', 'D', 'R', 'L'};
 
	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and mp[i][j] != '#';
	};
 
	auto borda = [&](int i, int j) {
		return i == 0 or j == 0 or i == n-1 or j == m-1;
	};
 
	auto espalha = [&]() {
		queue<ii> q;
		for (auto [i, j] : eles) {
			q.emplace(i, j);
			d_eles[i][j] = 0;
		}
 
		while (!q.empty()) {
			auto [ui, uj] = q.front(); q.pop();
 
			for (auto mov : movs) {
				int vi = ui + mov.f, vj = uj + mov.s;
				if (!valido(vi, vj) or d_eles[vi][vj] != -1) continue;
 
				q.emplace(vi, vj);
				d_eles[vi][vj] = d_eles[ui][uj] + 1;
			}
		}
	};
	espalha();
 
	vector<vector<ii>> pai(n, vector<ii>(m, ii(-1, -1)));
	vector<vector<char>> cam(n, vector<char>(m));
	auto fugir = [&]() {
		queue<ii> q; q.push(eu);
		d_eu[eu.f][eu.s] = 0;
 
		while (!q.empty()) {
			auto [ui, uj] = q.front(); q.pop();
			if (borda(ui, uj)) return saida = ii(ui, uj), 0;
 
			for (int i = 0; i < 4; i++) {
				ii mov = movs[i];
				int vi = ui + mov.f, vj = uj + mov.s;
				if (!valido(vi, vj) or d_eu[vi][vj] != -1) continue;
				if ((d_eles[vi][vj] != -1 and d_eles[vi][vj] <= d_eu[ui][uj]+1)) continue;
					
				q.emplace(vi, vj);
				d_eu[vi][vj] = d_eu[ui][uj] + 1;
				pai[vi][vj] = ii(ui, uj);
				cam[vi][vj] = trad[i];
			}
		}
		return 0;
	};
	fugir();
 
	if (saida.f == -1) return cout << "NO" << endl, 0;
 
	cout << "YES" << endl;
	string res = "";
	ii p = saida;	
	while (p.f != -1) {
		res.push_back(cam[p.f][p.s]);
		p = pai[p.f][p.s];
	}
	res.pop_back();
	reverse(res.begin(), res.end());
	cout << res.size() << endl << res << endl;
    
    return(0);
}
