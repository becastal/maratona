#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<int> P(n + 1), P_(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		P_[P[i]] = i;
	}

	for (int qi = 0, l, r, x, p; qi < q; qi++) {
		cin >> l >> r >> x; p = P_[x];
		
		if (p < l or p > r) {
			cout << -1 << " \n"[qi==q-1];
			continue;
		}

		int menores = x - 1, maiores = n - x;
		int esq = 0, dir = 0;
		while (l <= r) {
			int m = (l + r) / 2;

			if (m == p) {
				break;
			}

			if (m < p) {
				if (P[m] > x) {
					dir++;
				} else {
					menores--;
				}
				l = m + 1;
			} else {
				if (P[m] < x) {
					esq++;
				} else {
					maiores--;
				}
				r = m - 1;
			}

		}

		//cout << "esq: " << esq << endl;
		//cout << "dir: " << dir << endl;

		if (esq > maiores or dir > menores) {
			cout << -1 << " \n"[qi==q-1];
			continue;
		}

		cout << 2 * max(dir, esq) << " \n"[qi==q-1];
	}

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

