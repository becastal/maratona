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
	vector<int> A(n);

	for (int& i : A) {
		cin >> i;		
	}

	auto da = [&](int x, int h) {
		int dois = x / 2, uns = (x + 1) / 2;
		for (int i = 0; i < n; i++) {
			int a = A[i];
			int tira = min(dois, (h - a) / 2);
			dois -= tira, a += 2 * tira;

			tira = min(uns, h - a);
			uns -= tira, a += tira;
			if (a != h) return 0;
		}
		return 1;
	};

	int mx = *max_element(all(A));
	int l = 0, r = 1e18, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m, mx) or da(m, mx + 1)) {
			res = m;
			r = m-1;
		} else {
			l = m+1;
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

