#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int l, r; cin >> l >> r;
	int n = r - l + 1;	

	ll res = 0;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 30; j++) {
			if (i & (1 << j)) {
				res += (1 << j);
			}
		}
	}
	cout << 2 * res << endl;

	if (__builtin_popcount(n) == 1) {
		for (int i = n-1; i >= 0; i--) {
			cout << i << "\n "[!!i];
		}
		return 0;
	}

	set<int> S;
	int p = 1;
	while (p < n) S.insert(p), p <<= 1;
	S.insert(p);

	vector<int> A(n, -1);
	for (int i = n-1; i >= 0; i--) if (A[i] == -1) {
		int b = *S.upper_bound(i) - i - 1;
		A[i] = b;
		A[b] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << A[i] << " \n"[i == n-1];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

