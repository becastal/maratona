#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2e5+10;
int solve() {
	int n, k; cin >> n >> k;	

	vector<vector<int>> G(n);
	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[i].push_back(p);
		G[p].push_back(i);
	}
	
	int h = INT_MAX;
	vector<int> D(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			dfs(v, u);
		}
		if (u and G[u].size() == 1) h = min(h, D[u]);
	};
	dfs(0, -1);

	vector<int> V(h+1);
	for (int i = 0; i < n; i++) {
		if (D[i] <= h) V[D[i]]++;
	}

	bitset<MAX> dp;
	dp[0] = 1;

	int soma = 0;
	for (int i = 0; i <= h; i++) {
		dp |= (dp << V[i]);
		soma += V[i];
	}

	if (soma <= k or soma <= n - k) return cout << h+1 << endl, 0;

	for (int i = 0; i <= soma; i++) {
		if (dp[i] and i <= k and soma - i <= n - k) return cout << h+1 << endl, 0;
	}
	return cout << h << endl, 0;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

