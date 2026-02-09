#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<map<int, int>> G(n + 1);
	vector<int> nome(n + 1, -1);
	int t = 1;

	nome[0] = 0;
	for (int i = 0, xi, yi; i < n; i++) {
		cin >> xi >> yi;
		if (!G[nome[xi]].count(yi)) {
			G[nome[xi]][yi] = nome[i + 1] = t++;
		} else {
			nome[i + 1] = G[nome[xi]][yi];
		}
	}

	vector<vector<int>> nome_(n + 1);
	for (int i = 0; i <= n; i++) if (nome[i] != -1) {
		//cout << i << ' ' << nome[i] << endl;
		nome_[nome[i]].push_back(i);
	}

	vector<int> R(n + 1);
	int p = 0;
	function<void(int)> dfs = [&](int u) {
		for (int a : nome_[u]) {
			R[p++] = a;
		}

		for (auto [w, v] : G[u]) {
			dfs(v);
		}
	};
	dfs(0);

	for (int i = 1; i <= n; i++) {
		cout << R[i] << " \n"[i==n];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

