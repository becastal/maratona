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
	vector<int> A(n), C(m);
	for (int& i : A) {
		cin >> i; i--;
		C[i]++;
	}

	set<int> S(all(A));
	cout << ((int)S.size() == n ? "Yes" : "No") << endl;
	cout << (count(all(C), 0) ? "No" : "Yes") << endl;

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

