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

const vector<pair<int, int>> movimentos = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
vector<vector<char>> mapa;
vector<pair<int, int>> robos;
set<pair<int, int>> destinos;
vector<vector<vector<int>>> distancia;
int n;

bool movimentoValido(pair<int, int> mov)
{
    bool valido = true;

}

bool chegaramNosDestinos()
{

}

int bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    distancia.resize(n, vector<vector<int>>(n, vector<int>(3, INF)));

    while (!q.empty())
    {
        pair<int, int> v = q.front(); q.pop();
        for (auto u : movimentos)
        {
            if (movimentoValido(u))
            {
                // sei se eh tao simples!
            }
        }
    }
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        robos = vector<pair<int, int>>(3);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
        {
            cin >> mapa[i][j];
            if (mapa[i][j] >= 'A' && mapa[i][j] <= 'C') robos[mapa[i][j] - 'A'] = {i, j};
            if (mapa[i][j] == '#') destinos.insert({i, j});
        }

        int resposta = bfs();
        cout << "Case " << t << ": ";
        if (resposta == -1) cout << "trapped" << endl; else cout << resposta << endl;
    } 
    return(0);
}
