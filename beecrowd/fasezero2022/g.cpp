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

vector<pair<pair<int, int>, char>> movs = { {{-1, 0}, 'U'}, {{1, 0}, 'D'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};

bool segue(pair<int, int> posicao, pair<int, int> mov

string procura(string query)
{
	string resp = ":(";
	
	vector<pair<pair<int, int>, char>> caminhos;

	for (auto p : pos[query[0]])
	{
		for (auto mov : movs)
		{
			auto adj = {p.f + mov.f.f, p.s + mov.f.s};
			if (valido(adj) && caca[adj.f][adj.s] == query[1])
				if (segue(adj, mov.s.s, query))
					caminhos.push_back(caminho);
		}
	}

	if (caminhos.size())
	{
		sort(caminhos.begin(), caminhos.end());
		resp = to_string(caminhos.f.f) + " " + to_string(caminhos.f.s) + " " + caminhos.s.s;
	}

	return resp;
}

vector<vector<char>> caca;
vector<int, vector<pair<int, int>>> pos(27);

int main()
{
    _;

	int n, m; cin >> n >> m;
	caca = vector<vector<char>> (n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> caca[i][j];
			pos[caca[i][j] - 'A'].push_back({i, j});
		}

	int w; cin >> w;
	for (int i = 0; i < w; i++)
	{
		string palavra; cin >> palavra;
		cout << procura(palavra) << endl;
	}

    return(0);
}
