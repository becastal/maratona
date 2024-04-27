#include <iostream>
#include <vector>
#include <queue>
#define dbg(x) cout << #x << " = " << x << endl
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
vector<int> conexoes;
vector<pair<string, vector<string>>> atributos;
int n;

void bfs(int p)
{
    queue<int> q;
    q.push(p);
    visitado.clear(); visitado.resize(n);
    conexoes.clear(); conexoes.resize(n);

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        conexoes[v] = grafo[v].size();
        for (auto u : grafo[v])
        {
            if (!visitado[u])
            {
                q.push(u); visitado[u] = true;
            }
        }
    }
}

int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        
        grafo.resize(n); atributos.resize(n);
        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                int Fi; cin >> Fi; Fi--;
                if (Fi == -1) break;
                grafo[i].push_back(Fi);
            }
        }

        while (true)
        {
            int p; cin >> p; p--;
            if (p == -1) break;

            int t1, t2;
            cin >> t1 >> t2;
            string a1, a2, a3;
            cin >> a1 >> a2 >> a3;
            bfs(p);
            for (int i = 0; i < n; i++)
            {
                if (conexoes[i] < t1) atributos[i].second.push_back(a1);
                else if (conexoes[i] < t2) atributos[i].second.push_back(a2);
                else atributos[i].second.push_back(a3);
            }
        }

        for (int i = 0; i < n; i++) cin >> atributos[i].first;
        
        for (int i = 0; i < n; i++)
        {
            cout << atributos[i].first << ": ";
            for (auto a : atributos[i].second) cout << a << " ";
            cout << endl;
        }
        grafo.clear(); atributos.clear();
    }
}
