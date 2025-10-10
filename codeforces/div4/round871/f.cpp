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

void solve() {
	int n, m; cin >> n >> m;
	vector<int> deg(n, 0);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		deg[u]++, deg[v]++;
	}

	map<int, int> M;
	for (int i = 0; i < n; i++) {
		M[deg[i]]++;
	}

	vector<int> v;
	for (auto [a, b] : M) {
		v.push_back(b);
	}
	sort(v.begin(), v.end());

	if (v.size() == 3) {
		cout << v[1] << ' ' << v[2] / v[1] << endl;
	} else {
		cout << v[0]-1 << ' ' << v[1] / (v[0]-1) << endl;
	}
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
