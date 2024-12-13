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

int main()
{
    _;

    int n; 
    cin >> n;

    vector<vector<int>> g(11);
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v; 
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(11, -1);
    auto bfs = [&] () {
        queue<int> q; 
        q.push(0);
        d[0] = 1;
        
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();

            for (int v : g[u]) {
                if (d[v] != -1) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    };

    bfs();
    cout << d[8] << endl;
    
    return 0;
}

