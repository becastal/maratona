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

	int n, m; cin >> n >> m;
	int N = n + m + 1;

	vector<vector<int>> g(N);
	for (int i = 0, k; i < n; i++) {
		cin >> k;

		for (int j = 0, x; j < k; j++) {
			cin >> x; x--;
			g[i + m].push_back(x);
			g[x].push_back(i + m);
		}
	}

	// montar spanning agora
	int t = 1;
	vector<int> vis(N, 0), pai(N, -1);
	function<void(int)> dfs1 = [&](int u) {
		vis[u] = t;

		for (int v : g[u]) {
			if (vis[v]) continue;
			pai[v] = u;
			dfs1(v);
		}
	};

	for (int i = 0; i < n + m; i++) {
		if (!vis[i]) dfs1(i), t++;
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; a--, b--;

		if (vis[a] != vis[b]) {
			cout << -1 << endl;
			continue;
		}

		vector<int> A, B;
		for (int u = a; u != -1; u = pai[u]) {
			A.push_back(u);
		}
		for (int u = b; u != -1; u = pai[u]) {
			B.push_back(u);
		}

		int i = A.size() - 1, j = B.size() - 1;
		while (i >= 0 and j >= 0 and A[i] == B[j]) {
			i--, j--;
		}

		vector<int> res;
		for (int k = 0; k <= i+1; k++) {
			res.push_back(A[k]);	
		}
		for (int k = j; k >= 0; k--) {
			res.push_back(B[k]);	
		}

		cout << (res.size() + 1) / 2 << endl;
		for (int u : res) cout << (u < m ? u + 1 : u - m + 1) << ' '; cout << endl;
	}
    
    return(0);
}
