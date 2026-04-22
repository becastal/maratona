#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int k, m; cin >> k >> m;
	vector<array<int, 2>> A(k);
	for (auto& [c, l] : A) {
		cin >> c >> l;
	}
	reverse(all(A));

	int l = m * 10007;
	int nmodl = 0;
	for (auto [c, l] : A) {
			
	}
	cout << nmodl / m << endl;

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

