#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector<pair<int, int>> M(n);

	for (auto& [l, r] : M) cin >> l >> r;
	sort(M.begin(), M.end());

	vector<int> L(n), R(n);
	for (int i = 0; i < n; i++) {
		tie(L[i], R[i]) = M[i];
	}

	vector<int> melhor(n, n-1);
	for (int i = n-2; i >= 0; i--) {
		melhor[i] = (R[i] < R[melhor[i+1]] ? i : melhor[i+1]);
	}

	const int LOG = 25;
	vector<vector<int>> prox(n, vector<int>(LOG, -1));
	for (int i = 0; i < n; i++) {
		auto [l, r] = M[i];
		int pos = lower_bound(L.begin(), L.end(), r) - L.begin();
		if (pos < n) prox[i][0] = melhor[pos];
	}

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            prox[i][j] = (prox[i][j-1] < 0 ? -1 : prox[prox[i][j-1]][j-1]);
        }
    }

	while (q--) {
		int l, r; cin >> l >> r;
		int pos = lower_bound(L.begin(), L.end(), l) - L.begin();

		if (pos == n or R[melhor[pos]] > r) {
			cout << 0 << endl;
			continue;
		}

		int res = 1;
		for (int i = LOG-1, u = melhor[pos]; i >= 0; i--) {
			int v = prox[u][i];
			if (v >= 0 and R[v] <= r) {
				res += (1 << i);
				u = v;
			}
		}
		cout << res << endl;
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
