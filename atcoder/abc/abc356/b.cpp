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
	vector<int> A(m);
	for (int& i : A) {
		cin >> i;
	}

	for (int i = 0; i < n; i++) { 
		for (int j = 0, a; j < m; j++) {
			cin >> a;
			A[j] -= a;
		}
	}

	cout << (*max_element(all(A)) > 0 ? "No" : "Yes") << endl;

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

