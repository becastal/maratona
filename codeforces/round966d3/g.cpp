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

void solve() {
    int n, m; 
    cin >> n >> m;
    int t0, t1, t2; 
    cin >> t0 >> t1 >> t2;

    vector<vector<tuple<int, int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        u--, v--;	
        g[u].emplace_back(v, l1, l2);
        g[v].emplace_back(u, l1, l2);
    }

    set<pair<int, int>> prq;
    prq.insert({t0, n - 1});
    vector<int> d(n, -INF);
    d[n - 1] = t0;

    while (!prq.empty()) {
        auto [w, u] = *prq.rbegin();
        prq.erase(prev(prq.end()));
        
        for (auto [v, l1, l2] : g[u]) {
            int d1 = (w - l1 >= t2 or w <= t1 ? w - l1 : w - l2);	
            if (d1 == w - l2) d1 = max(d1, t1 - l1);

            if (d[v] < d1) {
                prq.erase({d[v], v});
                d[v] = d1;
                prq.insert({d1, v});
            }
        }
    }

    cout << (d[0] >= 0 ? d[0] : -1) << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
