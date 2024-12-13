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
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());

	int m; cin >> m;
	vector<int> b(m);
	for (int& i : b) cin >> i;
	sort(b.begin(), b.end());

	vector<vector<int>> g(n + m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (abs(a[i] - b[j]) <= 1) {
				g[i].push_back(n + j);
			}
		}
	}
	
	vector<int> vis(n + m, 0);
	auto dfs = [&] (int i) {
		for (int j : g[i]) {
			if (!vis[j]) {
				vis[j] = 1;
				return 1;
			}
		}
		return 0;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		res += dfs(i);	
	}
    
	cout << res << endl;

    return(0);
}
