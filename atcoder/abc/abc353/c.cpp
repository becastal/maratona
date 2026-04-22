#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, res = 0; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		res += (n - 1) * i;
	}

	sort(all(A));
	int cont = 0;
	for (int i = 0; i < n; i++) {
		cont += A.end() - lower_bound(A.begin() + i + 1, A.end(), 100000000 - A[i]);
	}
	cout << res - cont * 100000000 << endl;

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

