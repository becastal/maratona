// Este código é um exemplo de implementação do algoritmo de Edmonds-Karp, 
// que é uma versão específica do algoritmo de Ford-Fulkerson usada para calcular o fluxo máximo em uma rede de fluxo.
// O algoritmo de Edmonds-Karp utiliza buscas em largura (BFS) para encontrar o caminho aumentante de menor comprimento (em termos de arestas) 
// do nó de origem (source) até o nó de destino (sink).


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

ll max_flow(vector<vector<int>> adj, vector<vector<ll>> capacity, int source, int sink) {
    int n = adj.size();
    vector<int> parent(n, -1);
    
    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(source);
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int son : adj[node]) {
                ll w = capacity[node][son];
                if (w <= 0 || parent[son] != -1) continue;
                parent[son] = node;
                q.push(son);
            }
        }
        return parent[sink] != -1;
    };

    ll flow = 0;
    while (reachable()) {
        int node = sink;
        ll curr_flow = LINF;

        cout << "Caminho encontrado: ";
        while (node != source) {
            curr_flow = min(curr_flow, capacity[parent[node]][node]);
            cout << node + 1 << " <- ";
            node = parent[node];
        }
        cout << source + 1 << endl;
        cout << "Fluxo atual do caminho: " << curr_flow << endl;

        node = sink;
        while (node != source) {
            cout << "Reduzindo capacidade: " << parent[node] + 1 << " -> " << node + 1 
                 << " de " << capacity[parent[node]][node];
            capacity[parent[node]][node] -= curr_flow;
            cout << " para " << capacity[parent[node]][node] << endl;

            cout << "Aumentando capacidade residual: " << node + 1 << " -> " << parent[node] + 1 
                 << " de " << capacity[node][parent[node]];
            capacity[node][parent[node]] += curr_flow;
            cout << " para " << capacity[node][parent[node]] << endl;

            node = parent[node];
        }

        flow += curr_flow;
        cout << "Fluxo total até agora: " << flow << endl << endl;
    }

    return flow;
}

int main() {
    _;

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> capacity(n, vector<ll>(n));
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
        capacity[a][b] += c;
    }

    cout << "Fluxo máximo: " << max_flow(adj, capacity, 0, n - 1) << endl;

    return 0;
}

