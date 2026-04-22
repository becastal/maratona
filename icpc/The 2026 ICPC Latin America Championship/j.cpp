#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int p, d; cin >> p >> d;
	vector<int> A(p);

	for (int i = 0, x; i < d; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			A[j]++;
		}
		sort(A.begin(), A.begin() + x);
	}
	cout << *max_element(all(A)) << endl;

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

