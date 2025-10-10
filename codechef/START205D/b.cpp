#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;

	vector<int> D(n+1, -1);
	D[k] = 0;

	queue<int> Q;
	Q.push(k);
	while (Q.size()) {
		int u = Q.front(); Q.pop();

		for (int v : {u-1, u+1, n+1-u}) {
			if (v >= 1 and v <= n and D[v] == -1) {
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}
	}

	cout << D[n] << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

