#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> P(n), vis(n);
	for (int& i : P) cin >> i, i--;

	ll res = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		if (P[i] == i) {
			vis[i] = 1;
			continue;
		}

		ll agr = 0;
		for (int u = i; !vis[u]; u = P[u]) {
			vis[u] = 1;
			agr++;
		}
		res += agr * (agr - 1) / 2;
	}
	cout << res << endl;

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

