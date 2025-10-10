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
	setIO("where");

	int n; cin >> n;
	vector<string> a(n);
	for (auto& i : a) cin >> i;

	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
	vector<tuple<int, int, int, int>> foi;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int xx = x; xx < n; xx++) {
				for (int yy = y; yy < n; yy++) {
					vector<vector<int>> vis(n, vector<int>(n, 0));
					
					auto valido = [&](int i, int j) {
						return i >= x and i <= xx and j >= y and j <= yy;
					};

					function<void(int, int, int)> dfs = [&](int ui, int uj, char c) {
						vis[ui][uj] = 1;

						for (auto [di, dj] : movs) {
							int vi = ui + di, vj = uj + dj;
							if (!valido(vi, vj) or vis[vi][vj] or a[vi][vj] != c) continue;
							dfs(vi, vj, c);
						}
					};


					map<char, int> comp;
					for (int i = x; i <= xx; i++) {
						for (int j = y; j <= yy; j++) {
							if (vis[i][j]) continue;
							comp[a[i][j]]++;
							dfs(i, j, a[i][j]);
						}
					}

					if (comp.size() != 2) continue;
					if ((comp.begin()->s == 1 and comp.rbegin()->s > 1) or
						   (comp.rbegin()->s == 1 and comp.begin()->s > 1)) {
						foi.emplace_back(x, y, xx, yy);
					}
				}
			}
		}
	}

	int res = 0;

	for (int i = 0; i < (int)foi.size(); i++) {
		int ok = 1;
		auto [x, y, xx, yy] = foi[i];
		for (int j = 0; j < (int)foi.size(); j++) {
			if (i == j) continue;

			auto [x_, y_, xx_, yy_] = foi[j];
			ok &= !(x >= x_ and x <= xx_ and y >= y_ and y <= yy_ and
					xx >= x_ and xx <= xx_ and yy >= y_ and yy <= yy_);
		}

//		if (ok) {
//			for (int i = x; i <= xx; i++) {
//				for (int j = y; j <= yy; j++) {
//					cout << a[i][j];
//				}
//				cout << endl;
//			}
//			cout << endl;
//		}
		res += ok;
	}

	cout << res << endl;

    return(0);
}
