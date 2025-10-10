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
	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		if (i - a[i] >= 0) g[i - a[i]].push_back(i);
		if (i + a[i] < n) g[i + a[i]].push_back(i);
	}

	vector<int> res(n, -1);
	auto bfs = [&](int p) {
		vector<int> d(n, -1);
		queue<int> q;

		for (int i = 0; i < n; i++) {
			if ((a[i] & 1) == p) {
				d[i] = 0;
				q.push(i);
			}
		}

		while (q.size()) {
			int u = q.front(); q.pop();

			for (int v : g[u]) {
				if (d[v] != -1) continue;
				d[v] = d[u] + 1;	
				q.push(v);
			}
		}

		//for (int i : d) cout << i << ' '; cout << endl;
		for (int i = 0; i < n; i++) {
			if ((a[i] & 1) != p and d[i] != -1) { 
				res[i] = d[i];
			}
		}
	};
	bfs(0), bfs(1);

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
