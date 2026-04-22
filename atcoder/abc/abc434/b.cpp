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
	vector<int> C(m), S(m);
	for (int i = 0, a, b; i < n; i++){ 
		cin >> a >> b;
		S[a-1] += b;
		C[a-1]++;
	}

	cout << fixed << setprecision(10);
	for (int i = 0; i < m; i++) {
		cout << 1.0 * S[i] / C[i] << endl;
	}

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

