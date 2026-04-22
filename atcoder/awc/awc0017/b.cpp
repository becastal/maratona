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
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	for (int i = 0, p; i < m; i++) {
		cin >> p; p--;
		if (p) A[p-1]++;
		A[p]++;
		if (p + 1 < n) A[p+1]++;
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << " \n"[i==n-1];
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

