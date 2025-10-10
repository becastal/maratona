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
	int n, m; cin >> n >> m;
	random_device rd;
    mt19937_64 rng(rd());

	vector<unordered_set<int>> ruim(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		ruim[u].emplace(v);
		ruim[v].emplace(u);
	}

	vector<int> res(n);
	iota(res.begin(), res.end(), 0);
	
	for (int t = 0; t < 500; t++) {
		shuffle(res.begin(), res.end(), rng);

		int ok = 1;
		for (int i = 1; i < n; i++) {
			ok &= !ruim[res[i-1]].count(res[i]);
		}

		if (ok) {
			for (int i : res) cout << i+1 << ' '; cout << endl;	
			exit(0);
		}
	}

	cout << -1 << endl;
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
