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

const vector<pair<int, int>> movimentos = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<char>> mapa;
vector<vector<bool>> visitado;
int n, m;

bool posicaoValida(pair<int, int> pos)
{
    int i = pos.first, j = pos.second;
    return(i >= 0 && j >= 0 && i < n && j < m && !visitado[i][j] && mapa[i][j] == '.');
}

void dfs(pair<int, int> v)
{
    visitado[v.f][v.s] = true;
    for (auto u : movimentos)
    {
        u.f += v.f, u.s += v.s;
        if (posicaoValida(u))
        {
            visitado[u.f][u.s] = true;
            dfs(u);
        }
    }
}

int main()
{
    _;
    while (true)
    {
        scanf("%d %d", &n, &m);
        mapa = vector<vector<char>>(n, vector<char>(m));
        visitado = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            scanf(" %c", &mapa[i][j]);
        
        int quantidadeCores = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        {
            if (mapa[i][j] == '.' && !visitado[i][j])
            {
                quantidadeCores++;
                dfs({ i, j });
            }
        }
        printf("%d\n", quantidadeCores);
    }
    return(0);
}
