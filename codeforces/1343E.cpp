#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

/*
#include <bits/stdc++.h>
using namespace std;

// BFS from src: returns {dist[], parent[]}
// parent[v] = predecessor of v on the BFS‐tree (or -1).
pair<vector<int>, vector<int>> bfs(int src, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX), parent(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return {dist, parent};
}

// Reconstruct the path src->dst using parent[] from BFS(src).
vector<int> reconstruct_path(int src, int dst, const vector<int>& parent) {
    vector<int> path;
    if (parent[dst] == -1 && src != dst)
        return {};  // no path
    for (int cur = dst; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
        if (cur == src) break;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a, b, c;
    cin >> a >> b >> c;

    // Do the three BFS's
    auto [distA, parentA] = bfs(a, adj);
    auto [distB, parentB] = bfs(b, adj);
    auto [distC, parentC] = bfs(c, adj);

    int d_ab = distA[b];
    int d_bc = distB[c];

    // Find x* maximizing distB[x] subject to
    //  distA[x]+distB[x]==d_ab  AND  distB[x]+distC[x]==d_bc
    int best_x = -1, max_shared = -1;
    for (int x = 0; x < n; x++) {
        if (distA[x] + distB[x] == d_ab
         && distB[x] + distC[x] == d_bc
         && distB[x] > max_shared)
        {
            max_shared = distB[x];
            best_x = x;
        }
    }

    // Build P1 = a -> x* -> b
    auto path_a_x = reconstruct_path(a, best_x, parentA);
    auto path_b_x = reconstruct_path(b, best_x, parentB);
    // path_b_x is b->...->x*
    vector<int> path_x_b(path_b_x.rbegin(), path_b_x.rend());
    vector<int> path1 = path_a_x;
    for (int i = 1; i < (int)path_x_b.size(); i++)
        path1.push_back(path_x_b[i]);

    // Build P2 = b -> x* -> c
    vector<int> path2 = path_b_x;  // b->...->x*
    auto path_c_x = reconstruct_path(c, best_x, parentC);
    // path_c_x is c->...->x*
    vector<int> path_x_c(path_c_x.rbegin(), path_c_x.rend());
    for (int i = 1; i < (int)path_x_c.size(); i++)
        path2.push_back(path_x_c[i]);

    // Output
    cout << "Path a->b via " << best_x << ":";
    for (int v : path1) cout << " " << v;
    cout << "\nPath b->c via " << best_x << ":";
    for (int v : path2) cout << " " << v;
    cout << "\nShared edges: " << max_shared << "\n";

    return 0;
}

*/
