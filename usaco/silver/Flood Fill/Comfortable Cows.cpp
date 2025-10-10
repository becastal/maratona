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
	setIO("");

	int N = 4000;
	vector<vector<int>> a(N, vector<int>(N, 0));
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	int res = 0;
	auto confortavel = [&](int i, int j) {
		int r = 0;
		for (auto [di, dj] : movs) {
			r += !!a[i + di][j + dj];	
		}
		return r == 3;
	};

	function<void(int, int)> ajusta = [&](int i, int j) {

		auto desconforta = [&](int i, int j) {
			for (auto [di, dj] : movs) {
				if (a[i + di][j + dj]) continue;
				a[i + di][j + dj] = 2;
				res++;
				ajusta(i + di, j + dj);
			}
		};

		if (a[i][j] and confortavel(i, j)) {
			desconforta(i, j);
		}

		for (auto [di, dj] : movs) {
			if (a[i + di][j + dj] and confortavel(i + di, j + dj)) {
				desconforta(i + di, j + dj);
			}
		}
	};

	int n; cin >> n;
	while (n--) {
		int i, j; cin >> i >> j; i += 1500, j += 1500;

		if (!a[i][j]) a[i][j] = 1;
		else if (a[i][j] == 2) {
			a[i][j] = 1;
			res--;
		}

		ajusta(i, j);
		cout << res << endl;
	}

    return(0);
}
