#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef std::pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int n, m; 
vector<vector<char>> caca;
vector<vector<ii>> pos(27);
map<char, ii> movs = 
  { {'U', {-1, 0}}, 
	{'D', { 1, 0}}, 
	{'R', { 0, 1}}, 
	{'L', {0, -1}} };
map<pair<char, char>, char> dobra = 
  { { {'U', '1'}, 'D' },
	{ {'U', '2'}, 'L' },
	{ {'L', '1'}, 'D' },
	{ {'L', '4'}, 'U' },
	{ {'R', '2'}, 'D' },
	{ {'R', '3'}, 'U' },
	{ {'D', '3'}, 'L' },
	{ {'D', '4'}, 'D' } };

bool valido(ii& posicao, char c)
{
	return (posicao.f >= 0 and posicao.f < n and posicao.s >= 0 and posicao.s < m and 
			caca[posicao.f][posicao.s] == c);
}

bool ehdobra(ii& posicao)
{
	return (posicao.f >= 0 and posicao.f < n and posicao.s >= 0 and posicao.s < m and 
			caca[posicao.f][posicao.s] >= '1' and caca[posicao.f][posicao.s] <= '4');
}

bool dobravalida(ii& posicao, char dir)
{
	return (dobra.find({dir, caca[posicao.f][posicao.s]}) != dobra.end());
}

bool segue(ii& posicao, char mov, string& query)
{
	char dir = mov;
	ii prox = posicao;
	for (auto c : query)
	{
		prox.f += movs[dir].f, prox.s += movs[dir].s; if (ehdobra(prox))
		{
			if (!dobravalida(prox, dir)) return false;
			dir = dobra[make_pair(dir, caca[prox.f][prox.s])];
			prox.f += movs[dir].f, prox.s += movs[dir].s;
		}

		if (!valido(prox, c)) return false;
	}

	return true;
}

string procura(string query)
{
	string resp = ":(";
	
	vector<pair<ii, char>> caminhos;

	for (auto p : pos[query[0] - 'A'])
		for (auto mov : movs)
			if (segue(p, mov.f, query))
				caminhos.push_back({p, mov.f});

	if (!caminhos.empty())
	{
		sort(caminhos.begin(), caminhos.end());
		resp = to_string(caminhos[0].f.f) + " " + to_string(caminhos[0].f.s) + " " + caminhos[0].s;
	}

	return resp;
}

int main()
{
    _;

	cin >> n >> m;
	caca = vector<vector<char>> (n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> caca[i][j];
			if (caca[i][j] >= '1' and caca[i][j] <= '4') continue;
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
