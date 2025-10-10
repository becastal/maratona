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
typedef pair<int,int> ii;

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));

	map<char, int> MM = {
		{'L', 0},
		{'D', 1},
		{'R', 2},
		{'U', 3}
	};

	map<int, ii> Md = {
		{0, ii(0, -1)},
		{1, ii(1, 0)},
		{2, ii(0, 1)},
		{3, ii(-1, 0)}
	};
	auto valido = [&] (ii a) {
		return a.f >= 0 and a.f < n and a.s < m and a.s >= 0 and v[a.f][a.s] != '#';
	};

	ii eu;	
	int dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] != '.' and v[i][j] != '#') {
				eu = ii(i, j);
				dir = MM[v[i][j]];
			}
		}
	}

	vector<vector<int>> d(n, vector<int>(m, 0));
	d[eu.f][eu.s] = 1;
	for (int i = 0; i < (int)1e5; i++) {
		ii mov = Md[dir];
		ii neu = ii(eu.f + mov.f, eu.s + mov.s);

		//cout << eu.f << ' ' << eu.s << endl;

		if (valido(neu)) {
			d[neu.f][neu.s] = 1;
			eu = neu;
			continue;
		}

		int ok = 0;
		for (int i = 0; i < 3; i++) {
			dir = (dir + 1) % 4;
			ii mov = Md[dir];
			ii neu = ii(eu.f + mov.f, eu.s + mov.s);

			if (valido(neu)) {
				d[neu.f][neu.s] = 1;
				eu = neu;
				ok = 1;
				break;
			}
		}
		if (!ok) break;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += d[i][j];
		}
	}
	cout << res << endl;
    
    return(0);
}
