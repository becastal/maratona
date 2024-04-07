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

vector<vector<pair<int, int>>> grafo;
vector<int> distancia;
const int MAX = 1e3;

void dijkstra(int origem)
{
    priority_queue<pair<int, int>> q; q.push({0, origem});

    while (!q.empty())
    {
        int v = q.top().second, d = -q.top().first;
        q.pop();
        if (d > distancia[v]) continue;
        distancia[v] = d;
        for (auto u : grafo[v])
        {
            int w = d + u.first;
            if (distancia[u.s] > w) q.push({w, u.s});
        }
    }
}

int main() {
    vector<int> visitavel = {1, 2, 3, 4, 5};
    vector<pair<int*, int>> fila;

    for (int u = 0; u < visitavel.size(); ++u) {
        fila.push_back({&visitavel[u], u});
    }

    // Printing the values
    for (auto& pair : fila) {
        cout << "Pointer value: " << *(pair.first) << ", Second value: " << pair.second << endl;
    }

    return 0;
}
