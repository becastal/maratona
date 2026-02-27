#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--;
		A[a] = b;
	}

	int res = 0;
	for (int i : A) {
		res += i < k;
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

