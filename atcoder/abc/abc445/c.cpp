#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int expo(int a, int b, int m) {
	if (!b) return 1;
	int res = expo(a * a % m, b / 2, m);
	if (b & 1) res = res * a % m;
	return res;
}

int solve() {
	int n; cin >> n;
	vector<int> P(n);
	vector<vector<int>> G(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i]; P[i]--;
		if (P[i] != i) {
			G[P[i]].push_back(i);
		}
	}

	vector<int> vis(n), R(n);
	for (int i = 0; i < n; i++) if (!vis[i]) {
		vector<int> cic;	

		int u = i;
		for (; !vis[u]; u = P[u]) {
			vis[u] = 1;
		}

		for (int v = u; vis[v] != 2; v = P[v]) {
			vis[v] = 2;
			cic.push_back(v);
		}
		int tam = cic.size();

		for (int v = u, p = 0; vis[v] != 3; v = P[v]) {
			vis[v] = 3;
			R[v] = cic[(p + expo(10, 100, tam)) % tam];
		}

		function<void(int, int d)> dfs = [&](int v, int d) {
			R[v] = cic[((expo(10, 100, tam) - d) + tam) % tam];				
			vis[v] = 1;
			for (int vv : G[v]) {
				dfs(vv, d + 1);
			}
		};
		for (int v : G[u]) {
			dfs(v, 1);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << R[i] + 1 << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

