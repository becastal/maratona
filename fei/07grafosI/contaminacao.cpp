#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define dbg(x) cout << #x << " = " << x << endl
using namespace std;

const vector<pair<int, int>> movimentos = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const int MAX = 50;
char mapa[MAX][MAX];
int n, m;

bool posicaoValida(pair<int, int> pos)
{
    int i = pos.first, j = pos.second;
    return(mapa[i][j] == 'A' && i >= 0 && j >= 0 && i < n && j < m);
}

void bfs_contaminacao(vector<pair<int, int>> fontes)
{
    queue<pair<int, int>> q;
    for (auto f : fontes) q.push(f);

    while (!q.empty())
    {
        pair<int, int> v = q.front(); q.pop();
        for (auto u : movimentos)
        {
            u.first += v.first, u.second += v.second;
            if (posicaoValida(u))
            {
                q.push(u);
                mapa[u.first][u.second] = 'T';
            }
        }
    }
}

int main()
{
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<pair<int, int>> fontesContaminacao;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'T') fontesContaminacao.push_back({ i,j });
        }

        bfs_contaminacao(fontesContaminacao);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) cout << mapa[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return(0);
}