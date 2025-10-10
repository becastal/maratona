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

	int n; cin >> n;
	vector<ll> v(n);
	for (ll& i : v) cin >> i;
	
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((v[i] % 3 == 0 and v[i] / 3 == v[j]) or v[i] * 2 == v[j]) {
				g[i].push_back(j);
			}
		}
	}

	auto dfs = [&](int in) {
		vector<int> d(n, -1), pai(n, -1); d[in] = 0;
		stack<int> q; q.push(in);
		int out = -1, dout = 0;
		
		while (q.size()) {
			int u = q.top(); q.pop();

			if (d[u] > dout) {
				dout = d[u];
				out = u;
			}

			for (int v : g[u]) {
				if (d[v] != -1) continue;
				
				d[v] = d[u] + 1;
				pai[v] = u;
				q.push(v);
			}
		}

		if (dout < n-1) return vector<int>();

		vector<int> res;
		for (int u = out; u != -1; u = pai[u]) {
			res.push_back(u);
		}
		reverse(res.begin(), res.end());
		return res;
	};

	for (int i = 0; i < n; i++) {
		auto res = dfs(i);

		if (res.empty()) continue;
		for (int i : res) cout << v[i] << ' '; cout << endl;
		return 0;
	}
	assert(0);
    
    return(0);
}
