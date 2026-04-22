#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, a, b; cin >> n >> a >> b;

	int m = 1 << n;
	vector<int> D(m, -1); D[m >> 1] = 0;
	queue<int> Q; Q.push(m >> 1);

	while (Q.size()) {
		int u = Q.front(); Q.pop();

		for (int v : {u >> 1, ((u + (1 << n)) >> 1)}) if (D[v] == -1) {
			D[v] = D[u] + 1;
			Q.push(v);
		}
	}

	cout << max(D[a], D[b]) << endl;

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

