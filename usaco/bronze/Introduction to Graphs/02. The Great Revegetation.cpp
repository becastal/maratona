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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("revegetate");

	int n, m; cin >> n >> m;

	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> cor(n, -1);
	auto colore = [&] (int u) {
		int i;
		for (i = 1; i <= 4; i++) {
			int ok = 1;	

			for (int v : g[u]) {
				ok &= (i != cor[v]);
			}

			if (ok) break;
		}
		assert(i <= 4);
		cor[u] = i;
	};

	for (int i = 0; i < n; i++) {
		colore(i);
	}

	for (int i : cor) cout << i; cout << endl;

    return(0);
}
