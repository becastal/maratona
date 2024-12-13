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
	vector<vector<char>> M(n, vector<char>(m));
	vector<vector<int>> dist(n, vector<int>(m, -1));

	pair<int, int> in, out;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'A') in = pair<int, int>(i, j);
			if (M[i][j] == 'B') out = pair<int, int>(i, j);
		}
	}

	function<int(pair<int, int>)> valido = [&](pair<int, int> p) {
		int i = p.f, j = p.s;
		return i >= 0 and j >= 0 and i < n and j < m and M[i][j] != '#';
	};

	vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	vector<char> movsReverse = {'D', 'R', 'U', 'L'};

	function<void()> bfs = [&]() {
		queue<pair<int, int>> q; q.push(in);
		dist[in.f][in.s] = 0;

		while (q.size()) {
			pair<int, int> u = q.front(); q.pop();

			for (auto mov : movs) {
				pair<int, int> v = pair<int, int>(u.f + mov.f, u.s + mov.s);
				if (valido(v) and dist[v.f][v.s] == -1) {
					dist[v.f][v.s] = dist[u.f][u.s] + 1;
					q.push(v);
				}
			}
		}
	};
	bfs();

	if (dist[out.f][out.s] == -1) {
		cout << "NO" << endl;
		return 0;
	}

	string res = "";
	pair<int, int> agr = out;	
	while (dist[agr.f][agr.s] != 0) {
		for (int i = 0; i < 4; i++) {
			pair<int, int> mov = movs[i];
			pair<int, int> antes = pair<int, int>(agr.f + mov.f, agr.s + mov.s);

			if (dist[antes.f][antes.s] == dist[agr.f][agr.s] - 1) {
				agr = antes;	
				res.push_back(movsReverse[i]);
			}
		}
	}

	cout << "YES" << endl << res.size() << endl;
	reverse(res.begin(), res.end());
	cout << res << endl;
    
    return(0);
}
