#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> P(n), P_(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i];
		P_[P[i]-1] = i;
	}

	stack<int> S;
	vector<vector<int>> G(n);

	for (int i = n-1; i >= 0; i--) {
		while (S.size() and P[i] > P[S.top()]) {
			S.pop();
		}
		if (S.size()) {
			//cout << "a (" << i << ", " << S.top() << ")\n";
			G[i].push_back(S.top());
			G[S.top()].push_back(i);
		}
		S.push(i);
	}
	while (S.size()) S.pop();

	for (int i = 0; i < n; i++) {
		while (S.size() and P[i] < P[S.top()]) {
			S.pop();
		}
		if (S.size()) {
			G[i].push_back(S.top());
			G[S.top()].push_back(i);
		}
		S.push(i);
	}
	while (S.size()) S.pop();

	vector<int> R = P_, L = P_;
	for (int i = 1; i < n; i++) {
		if (L[i] > L[i-1]) {
			G[L[i]].push_back(L[i-1]);
			G[L[i-1]].push_back(L[i]);
			L[i] = L[i-1];
		}
	}

	for (int i = n-2; i >= 0; i--) {
		if (R[i] < R[i+1]) {
			G[R[i]].push_back(R[i+1]);
			G[R[i+1]].push_back(R[i]);
			R[i] = R[i+1];
		}
	}

	vector<int> vis(n, 0);
	vector<array<int, 2>> Re;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : G[u]) if (!vis[v]) {
			Re.push_back({u, v});
			dfs(v);
		}
	};
	dfs(0);
	if (count(all(vis), 1) < n) return cout << "No" << endl, 0;

	// 8???13

	cout << "Yes" << endl;
	for (auto& a : Re) {
		cout << P[a[0]] << ' ' << P[a[1]] << endl;
	}

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
