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

const int mod = 32768;

int main()
{
    _;

	int n; cin >> n;
	vector<int> v(n); 
	for (int& i : v) cin >> i;

	auto bfs = [&](int src) {
		queue<int> q; q.push(src);
		vector<int> d(mod, -1); d[src] = 0;

		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (!u) return d[u];

			for (auto v : {(u + 1) % mod, (2 * u) % mod}) {
				if (d[v] != -1) continue;

				q.push(v);
				d[v] = d[u] + 1;
			}
		}

		return INF;
	};

	for (int i : v) cout << bfs(i) << ' ';
	cout << endl;
    
    return(0);
}
