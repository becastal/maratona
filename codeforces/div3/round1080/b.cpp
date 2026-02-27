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
	vector<int> A(n + 1), vis(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) {
		vector<int> B, P;
		for (int j = i; j <= n; j *= 2) {
			vis[j] = 1;
			B.push_back(A[j]);
			P.push_back(j);
		}
		sort(all(B));
		for (int j = 0; j < (int)B.size(); j++) {
			A[P[j]] = B[j];
		}
	}

	cout << (is_sorted(all(A)) ? "YES" : "NO") << endl;

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

