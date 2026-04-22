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
	vector<int> A(n);

	for (int i = 0, m; i < n; i++) {
		cin >> m;
		for (int j = 0, a; j < m; j++) {
			cin >> a;
			A[i] |= (1 << a);
		}
	}

	int q; cin >> q;
	for (int i = 0, tp, a, b; i < q; i++) {
		cin >> tp >> a >> b; a--, b--;
		if (tp == 1) {
			cout << __builtin_popcountll(A[a] & A[b]) << endl;
		} else {
			cout << __builtin_popcountll(A[a] | A[b]) << endl;
		}
	}

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

