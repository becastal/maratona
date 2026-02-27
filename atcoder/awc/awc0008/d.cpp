#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	priority_queue<array<int, 2>> pq;
	vector<int> F(n), D(n);
	for (int i = 0; i < n; i++) {
		cin >> F[i] >> D[i];
		pq.push({F[i], i});
	}

	int res = 0;
	for (int i = 0; i < m; i++) {
		auto [x, id] = pq.top(); pq.pop();
		res += x;
		pq.push({max(0LL, x - D[id]), id});
	}
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

