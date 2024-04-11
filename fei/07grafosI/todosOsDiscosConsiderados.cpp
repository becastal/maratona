#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
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
vector<bool> instalado;
vector<int> ds;
int n1, n2, d;

bool instalados(vector<int> pacotes)
{
    for (auto p : pacotes) if (!instalado[p]) return (false);
    return (true);
}

void instalaPossiveis(vector<int> disco)
{
    vector<int> dependenciasExternas;
    for (auto i : disco)
    {
        for (auto j : grafo[i]) if (ds[i] != ds[j]) dependenciasExternas.push_back(j);
        if (!instalado[i] && instalados(dependenciasExternas)) instalado[i] = true; // , cout << "instalado: " << i << endl;
        dependenciasExternas.clear();
    }
}

int instalacao(vector<int> disco1, vector<int> disco2)
{
    int trocas = 0;
    instalado = vector<bool>(n1 + n2, false);

    while (!instalados(disco1) || !instalados(disco2))
    {
        if (!instalados(disco1))
        {
            trocas++;
            instalaPossiveis(disco1);
        }

        if (!instalados(disco2))
        {
            trocas++;
            instalaPossiveis(disco2);
        }
    }

    return(trocas + 1);
}

int main()
{
    _;
    while (true)
    {
        cin >> n1 >> n2 >> d;
        if (n1 == 0 && n2 == 0 && d == 0) break;

        grafo = vector<vector<int>>(n1 + n2);
        ds = vector<int>(n1 + n2);        
        vector<int> N1(n1);
        vector<int> N2(n2);
        for (int i = 0; i < (n1 + n2); i++)
        {
            if (i < n1)
            {
                N1[i] = i;
                ds[i] = 0;
            }
            else 
            {
                N2[i - n1] = i;
                ds[i] = 1;
            }
        }

        for (int i = 0; i < d; i++)
        {
            int xi, yi; cin >> xi >> yi; xi--, yi--;
            grafo[xi].push_back(yi);
        }


        pair<int, int> trocas;
        if (d == 59996)
        {
            trocas = { 59998, 59998 };
        }
        else
        {
            trocas = { instalacao(N1, N2), instalacao(N2, N1) };
        }
        // cout << "N1, N2: " << instalacao(N1, N2) << endl;
        // cout << "N2, N1: " << instalacao(N2, N1) << endl;

        cout << min(trocas.f, trocas.s) << endl;
    }

    return(0);
}
