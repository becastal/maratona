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

	vector<array<int, 2>> A(n);
	for (auto &[a, b] : A) {
		cin >> a >> b;
	}

	for (int i = 0; i < n; i++) {
		auto [xi, yi] = A[i];
		int d = LLONG_MIN, p = -1;
		for (int j = 0; j < n; j++) {
			auto [xj, yj] = A[j];
			int d_ = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);

			if (d_ > d) {
				d = d_;
				p = j;
			}
		}

		cout << (p + 1) << endl;
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

