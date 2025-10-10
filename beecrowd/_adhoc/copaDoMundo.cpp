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

int n;
vector<int> id, sz;

struct aresta 
{
    int u;
    int v;
    int w;
    bool operator<(const aresta& other) const {
        return w < other.w;
    }
};

int find(int x)
{
    return(id[x] = (id[x] == x ? x : find(id[x])));
}

void unir(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

int kruskal(vector<aresta>& g)
{
    id = vector<int>(n + 1); iota(id.begin(), id.end(), 0);
    sz = vector<int>(n + 1, 1);
	sort(g.begin(), g.end());
    double soma = 0;
    for (auto a : g)
        if (find(a.u) != find(a.v))
        {
            unir(a.u, a.v);
            soma += a.w;
        }
    return(soma);
}

int main()
{
    _;

	int n, f, r; cin >> n >> f >> r;

	vector<aresta> as(f + r);

	for (auto& ai : as)
		cin >> ai.u >> ai.v >> ai.w;

	cout << kruskal(as) << endl;

    return(0);
}
