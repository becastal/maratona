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

	int n, m; cin >> n >> m;
	
	vector<vector<ll>> d(n, vector<ll>(n, -1));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		ll w; cin >> w;	
		d[u][v] = d[v][u] = w;
	}

	ll res = LINF;

	for (int ii = 1; ii < (1 << n); ii++) {
		//if (!(ii & 1) or !(ii & (1 << (n-1)))) break;

		vector<int> cam;
		for (int j = 0; j < n; j++) {
			if (ii & (1 << j)) cam.push_back(j);	
		}

		do {
			if (cam[0] != 0 or cam.back() != n-1) continue;

			ll agr = 0;
			for (int i = 0; i < (int)cam.size()-1; i++) {
				if (d[cam[i]][cam[i+1]] == -1) {
					agr = LINF;
					break;
				}
				agr ^= d[cam[i]][cam[i+1]];
			}

			res = min(res, agr);
		} while (next_permutation(cam.begin(), cam.end()));
	}
	cout << res << endl;
    
    return(0);
}
