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

	int res = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		double pos = 0.0;
		int agr = 0;

		auto vai = [&](int d) {
			double pos_ = pos + d;
			agr += (pos < 0.0) ^ (pos_ < 0.0);
			pos = pos_;
		};

		for (int i = 0; i < n; i++) {
			vai(mask >> i & 1 ? +A[i] : -A[i]);		
		}
		res = max(res, agr);
	}
	cout << res << endl;

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

