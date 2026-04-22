#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> A(n), O(n);
	for (int& i : A) {
		cin >> i;
	}
	iota(all(O), 0);
	sort(all(O), [&](int i, int j) {
		if (A[i] != A[j]) return A[i] > A[j];
		return i > j;
	});

	int mn = LLONG_MAX, res = 0;
	for (int i = 0; i < n; i++) {
		if (mn > O[i]) {
			mn = O[i];
			res++;
		}
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

