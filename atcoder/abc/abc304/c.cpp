#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, d; cin >> n >> d;

	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
	}

	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int i) {
		vis[i] = 1;

		for (int j = 0; j < n; j++) if (i != j and !vis[j]) {
			if ((A[i][0] - A[j][0]) * (A[i][0] - A[j][0]) + (A[i][1] - A[j][1]) * (A[i][1] - A[j][1]) > d * d) continue;
			dfs(j);
		}
	};
	dfs(0);

	for (int i = 0; i < n; i++) {
		cout << (vis[i] ? "Yes" : "No") << endl;
	}

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

