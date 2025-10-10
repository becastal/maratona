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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("perimeter");

	int n; cin >> n;
	vector<string> a(n);
	for (auto& i : a) cin >> i;

	int perimetro = 0, area = 0;
	int rperimetro = 0, rarea = 0;

	vector<vector<int>> vis(n, vector<int>(n, 0));
	auto valido = [&](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < n;
	};
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	function<void(int, int)> dfs = [&](int ui, int uj) {
		area++;
		vis[ui][uj] = 1;

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;	
			if (!valido(vi, vj) or a[vi][vj] == '.') perimetro++;
			else if (!vis[vi][vj]) dfs(vi, vj);
		}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] or a[i][j] == '.') continue;	
			area = perimetro = 0;
			dfs(i, j);
			if (rarea < area) {
				rarea = area;
				rperimetro = perimetro;
			} else if (rarea == area) {
				rperimetro = min(rperimetro, perimetro);
			}
		}
	}
	cout << rarea << ' ' << rperimetro << endl;

    return(0);
}
