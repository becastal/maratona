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

struct DSU {
    vector<int> id, sz, cor;
    DSU(int n) : id(n), sz(n, 1), cor(n) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int i) {
        return (i == id[i] ? i : id[i] = find(id[i]));
    }

    void merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (sz[i] < sz[j]) swap(i, j);
        sz[i] += sz[j], id[j] = i;
        cor[i] += cor[j];
    }

    int cont(int i) {
        i = find(i);
        return cor[i];
    }
};

void solve() {
    int n; cin >> n;
    vector<int> v(n), vis(n, 0);
    for (int& i : v) cin >> i;

    DSU dsu(n);
    string s; cin >> s; int i = 0;
    for (char c : s) dsu.cor[i++] = (c-'0')^1;
    
    function<void(int)> dfs = [&](int u) {
        if (vis[u]) return;
        vis[u] = 1;
        if (v[u]-1 == u) return;

		dsu.merge(u, v[u]-1);
		dfs(v[u]-1);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
        cout << dsu.cont(i) << " \n"[i==n-1];
    }
}

int main()
{
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

