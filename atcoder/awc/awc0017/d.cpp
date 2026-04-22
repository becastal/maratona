#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<array<int, 3>> B(m);
	for (auto& [a, b, w] : B) {
		cin >> a >> b >> w; a--, b--;
	}

	int res = LLONG_MIN;
	for (int mask = 0; mask < (1 << n); mask++) if (__builtin_popcountll(mask) == k) {
		int agr = 0;
		for (int i = 0; i < n; i++) if (mask >> i & 1) {
			agr += A[i];
		}

		for (auto [a, b, w] : B) {
			if ((mask >> a & 1) and (mask >> b & 1)) {
				agr -= w;
			}
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

