#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	int m = ceil(sqrt(n));

	vector<map<int, int>> Bf(m);

	for (int i = 0; i < m; i++) {
		int l = i * m, r = min(n, (i + 1) * m);
		for (int j = l; j <= r; j++) {
			Bf[i][j]++;
		}
	}

	while (q--) {
		int tp; cin >> tp;

		if (!tp) {
			int k, v; cin >> k >> v; k--;
			Bf[k / m][A[k]]--;
			Bf[k / m][A[k] = v]++;
		} else {
			int l, r, x; cin >> l >> r >> x;

			int res = 0, l_ = l / m, r_ = r / m;

			if (l_ == r_) {
				for (int i = l; i <= r; i++) {
					res += (A[i] == x);
				}
			} else {
				for (int i = l, fim = (l_ + 1) * m - 1; i <= fim; i++) {
					res += (A[i] == x);
				}

				for (int i = l_+1; i <= r_-1; i++) {
					res += Bf[i][x];
				}

				for (int i = r_ * m; i <= r; i++) {
					res += (A[i] == x);
				}
			}

			cout << res << endl;
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

