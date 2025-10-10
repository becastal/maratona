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

vector<pair<int, int>> movimentos = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n;

bool valido(pair<int, int> a)
{
	return a.f >= 0 and a.s >= 0 and a.f < n and a.s < n;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		vector<vector<char>> mp(n, vector<char>(n));
		vector<pair<int, int>> p;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> mp[i][j];
				if (mp[i][j] == '1') p.push_back({i, j}); 
			}

		bool quad = true;
		for (auto pi : p)
		{
			int soma = 0;
			for (auto mov : movimentos)
				if (valido({pi.f + mov.f, pi.s + mov.s}))
					soma += (mp[pi.f + mov.f][pi.s + mov.s] == '1');
			quad &= (soma >= 2);
		}
		cout << (quad ? "SQUARE" : "TRIANGLE") << endl;
	}
    
    return(0);
}
