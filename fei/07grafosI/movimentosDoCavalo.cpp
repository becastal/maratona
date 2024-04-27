#include <iostream>
#include <vector>
#include <queue>
#define dbg(x) cout << #x << " = " << x << endl
using namespace std;

vector<pair<int, int>> movimentos = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} };
const int MAX = 8;
bool visitado[MAX][MAX];
int distancia[MAX][MAX];

bool posicaoValida(pair<int, int> pos)
{
    int i = pos.first, j = pos.second;
    return(!visitado[i][j] && i >= 0 && j >= 0 && i < MAX && j < MAX);
}

int bfs(pair<int, int> fonte, pair<int, int> fim)
{
    for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++)
    {
        visitado[i][j] = false; distancia[i][j] = -1;
    }
    queue<pair<int, int>> q;
    q.push(fonte);
    visitado[fonte.first][fonte.second] = true;
    distancia[fonte.first][fonte.second] = 0;

    while (!q.empty())
    {
        pair<int, int> u = q.front(); q.pop();
        if (u == fim) return(distancia[u.first][u.second]);
        for (auto v : movimentos)
        {
            v.first += u.first, v.second += u.second;
            if (posicaoValida(v))
            {
                q.push(v);
                visitado[v.first][v.second] = true;
                distancia[v.first][v.second] = 1 + distancia[u.first][u.second];
            }
        }
    }
}

int main()
{
    char j1, i1, j2, i2;
    while (cin >> j1 >> i1 >> j2 >> i2)
    {
        i1 -= '1', i2 -= '1';
        j1 -= 'a', j2 -= 'a';

        pair<int, int> inicio = { (int)i1, (int)j1 };
        pair<int, int> fim = { (int)i2, (int)j2 };

        int distancia = bfs(inicio, fim);
        cout << "To get from " << char(j1 + 'a') << char(i1 + '1') << " to " << char(j2 + 'a') << char(i2 + '1') << " takes " << distancia << " knight moves." << endl;
    }
}
