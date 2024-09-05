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

vector<int> level, work;

bool bfs(int source, int sink, vector<vector<int>>& adj, vector<vector<ll>>& capacity) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(source);
    level[source] = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (level[neighbor] == -1 && capacity[node][neighbor] > 0) {
                level[neighbor] = level[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return level[sink] != -1;
}

ll dfs(int node, ll flow, int sink, vector<vector<int>>& adj, vector<vector<ll>>& capacity, vector<tuple<int, int, ll>>& edges_used) {
    if (node == sink) return flow;
    for (int &i = work[node]; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (level[neighbor] == level[node] + 1 && capacity[node][neighbor] > 0) {
            ll min_flow = min(flow, capacity[node][neighbor]);
            ll pushed_flow = dfs(neighbor, min_flow, sink, adj, capacity, edges_used);
            if (pushed_flow > 0) {
                capacity[node][neighbor] -= pushed_flow;
                capacity[neighbor][node] += pushed_flow;
                edges_used.push_back({node, neighbor, pushed_flow});
                return pushed_flow;
            }
        }
    }
    return 0;
}

ll dinic(int source, int sink, vector<vector<int>>& adj, vector<vector<ll>>& capacity, vector<tuple<int, int, ll>>& edges_used) {
    ll max_flow = 0;
    while (bfs(source, sink, adj, capacity)) {
        work.assign(adj.size(), 0);
        while (ll flow = dfs(source, LINF, sink, adj, capacity, edges_used)) {
            max_flow += flow;
        }
    }
    return max_flow;
}

int main() {
    _;

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> capacity(n, vector<ll>(n));
    vector<vector<int>> adj(n);
    level.resize(n);
    work.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += c;
        capacity[v][u] += c;
    }

    int source = 0;
    int sink = n - 1;

    vector<tuple<int, int, ll>> edges_used;
    ll max_flow = dinic(source, sink, adj, capacity, edges_used);

    cout << "Max Flow: " << max_flow << endl;
    cout << "Edges used in the flow:" << endl;
    for (auto& edge : edges_used) {
        int u, v;
        ll flow;
        tie(u, v, flow) = edge;
        cout << u + 1 << " -> " << v + 1 << " with flow " << flow << endl;
    }

    return 0;
}

