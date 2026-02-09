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
	int x, y; cin >> x >> y; x--, y--;

	vector<string> v(n);
	for (auto& si : v) cin >> si;

	string ord; cin >> ord;
	map<char, pair<int, int>> movs = {
		{'L', make_pair(0, -1)},
		{'U', make_pair(-1, 0)},
		{'D', make_pair(1, 0)},
		{'R', make_pair(0, 1)},
	};

	auto valido = [&] (int xi, int yi) {
		return xi >= 0 and yi >= 0 and xi < n and yi < m and v[xi][yi] != '#';
	};
    
	int res = v[x][y] == '@';
	v[x][y] = '.';
	for (auto c : ord) {
		int nx = x + movs[c].f, ny = y + movs[c].s;
		if (valido(nx, ny)) {
			res += v[nx][ny] == '@';
			v[nx][ny] = '.';
			x = nx, y = ny;
		}
	}

	cout << x+1 << ' ' << y+1 << ' ' << res << endl;

    return(0);
}
