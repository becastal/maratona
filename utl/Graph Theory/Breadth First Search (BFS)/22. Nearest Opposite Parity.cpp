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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		int l = i - v[i], r = i + v[i];
		if (l >= 0) g[l].push_back(i);
		if (r  < n) g[r].push_back(i);
	}

	vector<int> res(n, -1);
	auto bfs = [&](bool imp) {
		vector<int> d(n, -1);
		queue<int> q; 
		for (int i = 0; i < n; i++) {
			if ((v[i] & 1) == imp) {
				q.push(i);
				d[i] = 0;
			}
		}
		
		while (!q.empty()) {
			int a = q.front(); q.pop();

			for (int b : g[a]) {
				if (b < 0 or b >= n or d[b] != -1) continue;

				q.push(b);
				d[b] = d[a] + 1;
			}
		}
		
		for (int i = 0; i < n; i++) {
			if ((v[i] & 1) != imp and d[i] != -1) {
				res[i] = d[i];	
			}
		}
	};
	bfs(0), bfs(1);

	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;

    
    return(0);
}
