#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	vector<int> O(n), S(n);
	vector<vector<int>> A(n, vector<int>(n)), R(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			if (c == '1') {
				S[i]++;
				R[i].push_back(j);
				A[i][j] = 1;
			}
		}
	}

	iota(all(O), 0);
	sort(all(O), [&](int i, int j) {
		return S[i] > S[j];
	});

	vector<array<int, 2>> E;
	vector<vector<int>> Foi(n, vector<int>(n)), G(n), Arv(n);
	for (int i = 0; i < n; i++) {
		int u = O[i];
		for (int j = i + 1; j < n; j++) {
			int v = O[j];
			if (A[u][v] and !Foi[u][v]) {
				G[u].push_back(v);
				Arv[u].push_back(v);
				Arv[v].push_back(u);
				E.push_back({u, v});		
				if (E.size() >= n) return cout << "No" << endl, 0;
				for (int k : R[v]) {
					Foi[u][k] = 1;						
				}
			}
		}
	}
	if (E.size() != n-1) return cout << "No" << endl, 0;

	vector<int> VisArv(n);
	function<void(int)> dfs = [&](int u) {
		VisArv[u] = 1;
		for (int v : Arv[u]) if (!VisArv[v]) {
			dfs(v);
		}
	};
	dfs(0);
	if (count(all(VisArv), 0)) return cout << "No" << endl, 0;

	function<void(int, vector<int>&)> dfs2 = [&](int u, vector<int>& Vis) {
		Vis[u] = 1;
		for (int v : G[u]) if (!Vis[v]) {
			dfs2(v, Vis);
		}
	};

	vector<vector<int>> VisG(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		dfs2(i, VisG[i]);
	}
	if (A != VisG) return cout << "No" << endl, 0;

	cout << "Yes" << endl;
	for (auto [a, b] : E) {
		cout << a + 1 << ' ' << b + 1 << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

