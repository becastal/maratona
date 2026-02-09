#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	eu acho que so: caminha la nele no grafo ate reconhecer
	todos os vertices com dfs ou algo parecido.

	dai onde parar eu consigod dizer a sequencia de vertices
	que me leva ate o vertice n.

	na real eu paro no n antes ne
*/

int solve() {
	int n, m; cin >> n >> m;

	auto query = []() {
		int k; cin >> k;
		vector<int> R(k);
		for (int& i : R) cin >> i;
		return R;
	};

	vector<int> vis(n + 1, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		vis[u] = 1;
		if (u == n) {
			string ok; cin >> ok;
			exit(0);
		}

		for (int v : query()) if (!vis[v]) {
			cout << v << endl;
			dfs(v, u);	
		}

		cout << p << endl;
		query();
	};
	dfs(1, 1);

	return(0);
}

int main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

