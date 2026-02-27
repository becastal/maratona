#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k, resc = 0, ress = 0; cin >> n >> m >> k;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	for (int i = 0, j; i < m; i++) {
		cin >> j; j--;

		if (A[j] < k) {
			resc++, ress += A[j];
		}
	}
	cout << resc << ' ' << ress << endl;

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

