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
vector<bool> visitado;
vector<int> visitavel;
vector<vector<int>> chave; 
int n, m;

bool compara(const pair<int*, int>& a, const pair<int*, int>& b)
{
    return *a.first < *b.first;
}

bool bfs()
{
    visitavel = vector<int>(n); visitado = vector<bool>(n);
    visitavel[0] = 1; visitado[0] = true;
    vector<pair<int*, int>> fila;
    int *ptr = &visitavel[0];
    fila.push_back({ptr, 0});

    int salasVisitadas = 0;
    while (!fila.empty())
    {
        salasVisitadas++;
        sort(fila.begin(), fila.end(), compara);
        pair<int*, int> v = fila.back();
        fila.pop_back();
        if (*v.first == 1)
        {
            for (auto c : chave[v.s]) visitavel[c] = 1;
            for (auto u : grafo[v.s])
            {
                if (!visitado[u])
                {
                    visitado[u] = true;
                    fila.push_back({&visitavel[u], u});
                }
            }
        }
        else return false;
    }
    if (salasVisitadas != n) return false;
    return true;
}

int main()
{
    while (cin >> n >> m)
    {
        grafo = vector<vector<int>>(n);
        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b; a--, b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        chave = vector<vector<int>>(n);
        for (int i = 1; i <= n - 1; i++)
        {
            int c; cin >> c; c--;
            chave[c].push_back(i);
        }

        bool resposta = bfs();
        if (resposta) cout << "sim" << endl; else cout << "nao" << endl;
    }
}