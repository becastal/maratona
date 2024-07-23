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
vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (auto& l : v)
		for (auto& c : l)
			cin >> c;

	function<bool(int, int)> valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;
	};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			bool maior = true;
			for (auto mov : movs)
				if (valido(i + mov.f, j + mov.s))
					maior &= (v[i][j] > v[i + mov.f][j + mov.s]);

			if (maior)
			{
				int novo = -INF;
				for (auto mov : movs)
					if (valido(i + mov.f, j + mov.s))
						novo = max(novo, v[i + mov.f][j + mov.s]);
				v[i][j] = novo;
			}
		}

	for (auto& l : v)
	{
		for (auto& c : l)
			cout << c << ' ';
		cout << endl;
	}
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
		solve();
    
    return(0);
}
