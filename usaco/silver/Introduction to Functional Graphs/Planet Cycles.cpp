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

int solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (int& i : p) cin >> i, i--;

	int ciclo = 0;
	vector<int> res(n, -2), prof(n, 0);
	function<void(int, int)> dfs = [&](int u, int d) {
		prof[u] = d, res[u] = -1;

		if (res[p[u]] == -2) dfs(p[u], d + 1);
		if (res[p[u]] == -1) {
			int tam = (d + 1) - prof[p[u]];
			int v = p[u], v_ = v;
			do {
				res[v] = tam;
				v = p[v];
			} while (v != v_);
		}
		if (res[u] == -1) res[u] = res[p[u]] + 1;
	};

	for (int i = 0; i < n; i++) {
		if (res[i] == -2) dfs(i, 0);
	}

	for (int i : res) cout << i << ' '; cout << endl;

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
