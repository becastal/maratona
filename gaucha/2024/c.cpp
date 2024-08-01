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

vector<int> id, sz;
int find(int x) {
    return(id[x] = (id[x] == x ? x : find(id[x])));
}

void unir(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

int main()
{
    _;

	int n; cin >> n;
	vector<vector<int>> adj(n, vector<int> (n, 0));
	vector<tuple<int, int, int>> ar;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
			if (i == j) continue;

			ar.push_back({adj[i][j], i, j});
		}

	sz.assign(ar.size(), 1);
	id.resize(ar.size());
	iota(id.begin(), id.end(), 0);

	sort(ar.begin(), ar.end());
	for (auto [w, i, j] : ar)
		if (find(i) != find(j))
			unir(i, j);

	// agora talvez no mst achar o caminho em que eu passo por todos os vertices.
    
    return(0);
}
