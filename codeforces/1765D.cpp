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
	sort(all(A));

	auto da = [&](int mid) {
		multiset<int> mul;
		for (int i = 0; i < mid; i++) {
			mul.insert(A[i]);
		}

		int u = A[mid-1];
		mul.erase(mul.find(u));
		for (int i = 0; i < mid - 1; i++) {
			// ultimo v tal que u + v <= m -> v <= m - u

			auto it = mul.upper_bound(m - u);
			if (it == mul.begin()) return 0;
			int v = *prev(it);
			assert(u + v <= m);

			u = v;
			mul.erase(mul.find(u));
		}
		
		return 1;
	};

	int l = 1, r = n, res = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}

	cout << n + accumulate(all(A), 0LL) - res + 1<< endl;

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

