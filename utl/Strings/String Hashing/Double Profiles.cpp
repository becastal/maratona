#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

	1: 2, 3
	2: 1, 3
	3: 1, 3
*/

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}


int solve() {
	int n, m; cin >> n >> m;

	vector<int> H(n);
	for (int i = 0; i < n; i++) {
		H[i] = uniform(256, 1000000000000000000LL);
	}

	vector<vector<int>> G(n);
	vector<int> Set(n);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		Set[a] ^= H[b];
		Set[b] ^= H[a];
		G[max(a, b)].push_back(min(a, b));
	}

	int res = 0;
	for (int u = 0; u < n; u++) {
		for (int v : G[u]) {
			if ((Set[u] ^ H[v]) == (Set[v] ^ H[u])) res++;
		}
	}

	map<int, int> M;
	for (int i = 0; i < n; i++) {
		res += M[Set[i]]++;
	}
	cout << res << endl;

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

