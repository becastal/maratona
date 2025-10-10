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
    
    int n, m; 
    cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> z[i]; x[i]--, y[i]--;
        g[x[i]].emplace_back(y[i], z[i]);
        g[y[i]].emplace_back(x[i], z[i]);
    }
    
    vector<int> a(n, 0), vis(n, 0), cc;
    
    function<int(int)> dfs = [&](int u) {
		cc.push_back(u);
        for (auto [v, w] : g[u]) {
            if (vis[v]) {
                if ((a[u] ^ a[v]) != w) return 0;
            } else {
                vis[v] = 1;
                a[v] = a[u] ^ w;
                if (!dfs(v)) return 0;
            }
        }
        return 1;
    };
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
			cc.clear();
            if (!dfs(i)) return cout << -1 << endl, 0;

			int base = 0;	
			for (int i = 0; i < 31; i++) {
				int cont = 0;
				for (int j : cc) {
					if (a[j] & (1 << i)) cont++;
				}
				if (2 * cont > cc.size()) base |= (1 << i);
			}

			for (int j : cc) {
				a[j] ^= base;
			}
        }
    }
    
    for (int i : a) cout << i << ' '; cout << endl;
    
    return(0);
}

