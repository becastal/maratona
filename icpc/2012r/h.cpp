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

map<vector<int>, int> hasher;
int hashify(vector<int> x) {
    sort(x.begin(), x.end());
    if(!hasher[x]) {
        hasher[x] = hasher.size();
    }
    return hasher[x];
}
class Tree
{
    public:
    vector<vector<int>> adj;
    vector<int> sub, pai;
    int r[2], hs[2], n, bt = 0;
    Tree(int x): n(x)
    {
        adj.resize(n+1);
        sub.resize(n+1, 0);
        pai.resize(n+1);
    }
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dfs(int u, int p = -1)
    {
        vector<int>  at;
        for(int v:adj[u])
        {
            if(v == p)
                continue;
            at.push_back(dfs(v, u));
        }
        return hashify(at);
    }
    void dfs_sub(int u, int p = -1)
    {
        pai[u] = p;
        sub[u] = 1;
        for(int v:adj[u])
        {
            if(v == p)
                continue;
            dfs_sub(v, u);
            sub[u]+=sub[v];
        }
    }
    int find_centroid(int u, int p = -1)
    {
        // cout << u << '\n';
        for(int v:adj[u])
        {
            if(v == p)
                continue;
            if(2*sub[v] > n)
                return find_centroid(v, u);
        }
        return u;
    }
    void build()
    {
        bt = 1;
        dfs_sub(1);
        r[1] = r[0] = find_centroid(1);
        for(int v:adj[r[0]])
        {
            if(v == pai[r[0]])
            {
                if(2*(n-sub[r[0]]) >= n)
                    r[1] = v;
            }else
            {
                if(2*sub[v] >= n)
                    r[1] = v;
            }
        }
        hs[0] = dfs(r[0]);
        hs[1] = dfs(r[1]);
    }


    bool isIsomorphic(Tree t2)
    {
        if(!bt)
            build();
        if(!t2.bt)
            t2.build();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
                if(hs[i] == t2.hs[j]){
                    // cout << r[i] << ' ' << t2.r[j] << "<<<\n";
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    _;
    
	int n;
	while (cin >> n) {
		Tree a(n), b(n);

		for (int i = 0, u, v; i < n-1; i++) {
			cin >> u >> v; u--, v--;
			a.add_edge(u, v);
		}

		for (int i = 0, u, v; i < n-1; i++) {
			cin >> u >> v; u--, v--;
			b.add_edge(u, v);
		}

		cout << (a.isIsomorphic(b) ? 'S' : 'N') << endl;
	}

    return(0);
}
