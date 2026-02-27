#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n);

	for (int& i : A) cin >> i;

	vector<int> P(A);
	for (int i = 1; i < n; i++) {
		P[i] += P[i-1];
	}

	vector<vector<array<int, 2>>> G(n);
	for (int i = 0; i < n; i++) { 
		cin >> B[i]; B[i]--;
		G[i].push_back({B[i], A[i]});
		if (i) G[i].push_back({i - 1, 0});
	}

	vector<int> D(n, LLONG_MAX); D[0] = 0;
	priority_queue<array<int, 2>> pq; pq.push({0, 0});

	while (pq.size()) {
		auto [du, u] = pq.top(); pq.pop();
		if (D[u] != -du) continue;

		for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
			D[v] = D[u] + w;
			pq.push({-D[v], v});
		}
	}

	int res = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, P[i] - D[i]);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

