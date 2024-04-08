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

vector<vector<int>> grafo;
vector<int> distancia;
vector<int> carta;
vector<pair<int, int>> pares;
vector<int> pai;
int n, m;

int dfs(int origem)
{
    distancia = vector<int>(n, -1);
    pai = vector<int>(n);
    stack<int> s;
    s.push(origem); distancia[origem] = 0;
    int chegada = carta[origem];

    while (!s.empty())
    {
        int v = s.top(); s.pop();
        for (auto u : grafo[v])
        {
            if (distancia[u] == -1)
            {
                distancia[u] = distancia[v] + 1;
                pai[u] = v;
                s.push(u);
            }
        }
    }
    return(0);
}

int distanciaEntrePares(pair<int, int>)
{
    
}

int main()
{
    _;
    cin >> n;
    m = n - 1;

    carta = vector<int>(n);
    pares = vector<pair<int, int>>(n / 2);
    for (int i = 0; i < n; i++) cin >> carta[i];

    grafo.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(0);
    int pontos = 0;


    return(0);
}