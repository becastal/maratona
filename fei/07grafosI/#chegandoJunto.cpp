#include <iostream>
#include <vector>
#include <stack>
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
vector<int> pai;
int n, m;

int dfs(int origem)
{
    distancia = vector<int>(n, -1);
    pai = vector<int>(n);
    stack<int> s;
    s.push(origem); distancia[origem] = 0;

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

int distanciaEntreNodos(int v, int u)
{
    int p = 0;
    while (v != u)
    {
        if (distancia[v] >= distancia[u])
        {
            v = pai[v]; p++;
        }
        else
        {
            u = pai[u]; p++;
        }
    }

    return(p);
}

int main()
{
    _;
    cin >> n;
    m = n - 1;

    carta = vector<int>(n);
    vector<vector<int>> pares (n / 2);
    for (int i = 0; i < n; i++)
    {
        cin >> carta[i];
        pares[carta[i]-1].push_back(i);
    }

    grafo.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(0);
    int pontos = 0;
    for (int i = 0; i < n / 2; i++)
    {
        pontos += distanciaEntreNodos(pares[i][0], pares[i][1]);
    }
    cout << pontos << endl;

    return(0);
}
