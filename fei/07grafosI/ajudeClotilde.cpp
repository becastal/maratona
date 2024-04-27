#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define dbg(x) cout << #x << " = " << x << endl
using namespace std;

const int MAX = 1e5 + 1;
vector<int> distancia;
vector<bool> visitado;
vector<bool> canalInvalido(MAX, false);
int o, d, k;

vector<int> movimentos(int n)
{
    vector<int> resp = { n * 3, n * 2, n + 1, n - 1 };
    if (n % 2 == 0) resp.push_back(n / 2);

    return(resp);
}

bool canalValido(int c)
{
    return(c > 0 && c <= MAX && !visitado[c] && !canalInvalido[c]);
}

int bfs(int origem)
{
    queue<int> q;
    q.push(origem);
    visitado.resize(MAX, false);
    distancia.resize(MAX, false);
    visitado[origem] = true;
    distancia[origem] = 0;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (auto u : movimentos(v))
        {
            if (canalValido(u))
            {
                visitado[u] = true;
                q.push(u);
                distancia[u] = distancia[v] + 1;
                if (u == d) return(distancia[u]);
            }
        }
    }
    return(-1);
}

int main()
{
    while (true)
    {
        cin >> o >> d >> k;
        if (o == 0 && d == 0 && k == 0) break;

        canalInvalido.resize(MAX);
        for (int i = 0; i < k; i++)
        {
            int canal; cin >> canal;
            canalInvalido[canal] = true;
        }

        int resposta = bfs(o);
        // if (resposta == 10) cout << "INPUTS: " << o << "(o), " << d << "(d), " << k << " (k)\n";
        cout << resposta << endl;
        distancia.clear(); visitado.clear(); canalInvalido.clear();
    }

    return(0);
}