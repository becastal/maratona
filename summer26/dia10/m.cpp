#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	if (!k) return cout << accumulate(all(A), 0LL) << endl, 0;

	sort(rall(A));
	int mx = A[0];
	int ac = accumulate(A.begin() + k, A.end(), 0LL);
	//cout << "mx: " << mx << endl;
	//cout << "ac: " << ac << endl;
	cout << max(mx, ac) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    //
    return(0);
}
