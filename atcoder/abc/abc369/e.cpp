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

ll solve() {
	ll res = INF;
	ll dp[5][2];
	vector<int> b;
	for (int i = 0; i < k; i++) {
		b.push_back(i);
	}

	while(1) {
			
		if (!next_permutation(b.begin(), b.end())) break;
	}
	return res;
}

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<ll>> d(n, vector<ll>(n, LINF));
	vector<int> u(n), v(n), w(n);
	for (int i = 0; i < n; i++) d[i][i] = 0;

	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i]; u[i]--, v[i]--;
		d[u[i]][v[i]] = min(d[u[i]][v[i]], w[i]);
		d[v[i]][u[i]] = min(d[v[i]][u[i]], w[i]);
	}

	for (int b = 0; b < n; b++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				d[a][c] = min(d[a][c], d[a][b] + d[b][c]);
			}
		}
	}

	cim >> m;
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		vector<int> a;
		for (int i = 0, x; i < k; i++) {
			cin >> x; a.push_back(x-1);
		}
		cout << solve() << endl;
	}
    
    return(0);
}
