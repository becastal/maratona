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
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}
	for (int i = 0; i < n; i++) if (A[i][i] == '0') {
		return cout << "No" << endl, 0;
	}

	vector<vector<int>> G(n), Arv(n);
	vector<int> Pai(n, -1);
	vector<array<int, 2>> E;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j and A[i][j] == '1') {
			int ehpai = 1;
			for (int k = 0; k < n; k++) if (k != i and k != j) {
				if (A[i][k] == '1' and A[k][j] == '1') {
					ehpai = 0;
					break;
				}
			}
			if (ehpai) {
				G[i].push_back(j);
				Arv[i].push_back(j);
				Arv[j].push_back(i);
				E.push_back({i, j});
			}
		}
	}

	if (E.size() != n-1) return cout << "No" << endl, 0;
	function<void(int, int, string&)> dfs = [&](int u, int p, string& Vis) {
		Vis[u] = '1';
		for (int v : G[u]) if (Vis[v] != '1' and v != p) {
			dfs(v, u, Vis);	
		}
	};

	vector<int> Vis(n);
	function<void(int, int)> dfs2 = [&](int u, int p) {
		Vis[u] = 1;	
		for (int v : Arv[u]) if (!Vis[v] and v != p) {
			dfs2(v, u);	
		}
	};
	dfs2(0, -1);
	if (count(all(Vis), 0)) return cout << "No" << endl, 0;

	vector<string> B(n, string(n, '0'));
	for (int i = 0; i < n; i++) {
		dfs(i, -1, B[i]);
	}
	if (A != B) return cout << "No" << endl, 0;

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

