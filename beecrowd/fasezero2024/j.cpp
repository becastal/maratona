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


bool valido(ii p, int n, int m, vector<vector<char>>& tab)
{
	return (p.f >= 0 and p.f < n and p.s >= 0 and p.s < m and tab[p.f][p.s] == '.');
}

vector<ii> movimentos(int k, int l)
{
	int ki = k - 1, li = l - 1;
	
	set<ii> movs;
		movs.insert({+ki, +li});
		movs.insert({+ki, -li});
		movs.insert({-ki, +li});
		movs.insert({-ki, -li});
		movs.insert({+li, +ki});
		movs.insert({+li, -ki});
		movs.insert({-li, +ki});
		movs.insert({-li, -ki});

	vector<ii> resp;
	for (auto p : movs)
		resp.push_back(p);

	return resp;
}

int main()
{
    _;

	int n, m; cin >> n >> m;
	int k, l; cin >> k >> l;

	vector<vector<char>> tab(n, vector<char>(m));
	vector<vector<int>> cont(n, vector<int>(m, 0));
	vector<ii> peoes, casas;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tab[i][j];
			if (tab[i][j] == '*')
				peoes.push_back({i, j});
			else
				casas.push_back({i, j});
		}

	for (auto p : peoes)
		for (auto mov : movimentos(k, l))
			if (valido({p.f + mov.f, p.s + mov.s}, n, m, tab))
				cont[p.f + mov.f][p.s + mov.s]++;

	int maior = -INF;	
	ii pos = casas[0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (tab[i][j] == '.' and cont[i][j] > maior)
			{
				maior = cont[i][j];
				pos = {i, j};
			}

	cout << pos.f + 1 << " " << pos.s + 1 << endl;
    
    return(0);
}
