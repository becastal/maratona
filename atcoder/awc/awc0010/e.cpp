#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;

	vector<vector<int>> C(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> C[i][j];
		}
	}

	auto calc = [n](vector<int> P) {
		vector<int> vis(n, 0);
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			res++;
			int v = i;
			while (!vis[v]) {
				vis[v] = 1;
				v = P[v];
			}
		}
		return n - res;
	};

	int res = LLONG_MIN;
	vector<int> P(n);
	iota(all(P), 0);

	do {
		if (calc(P) > k) continue;

		int agr = 0;
		for (int i = 0; i < n - 1; i++) {
			agr += C[P[i]][P[i+1]];	
		}
		agr += C[P[n-1]][P[0]];
		
		res = max(res, agr);
	} while (next_permutation(all(P)));
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

