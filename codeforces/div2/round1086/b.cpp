#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, p, m; cin >> n >> k >> p >> m; p--;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<int> P(n);
	iota(all(P), 0);

	int res = 0;
	for (int s = 0;;) {
		int mn = LLONG_MAX, pos = 0;
		for (int i = 0; i < k; i++) {
			if (P[i] == p) {
				pos = i;
				break;
			} else {
				if (mn > A[P[i]]) {
					mn = A[P[i]];
					pos = i;
				}
			}
		}
		int v = P[pos];
		P.erase(P.begin() + pos);
		P.push_back(v);

		s += A[v];
		if (s > m) break;
		res += (v == p);
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
