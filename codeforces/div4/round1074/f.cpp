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
	vector<int> A(1 << n);
	for (int& i : A) {
		cin >> i;
	}

	vector<int> Seg(1 << (n + 1)), Pos(1 << (n + 1));
	function<int(int, int, int)> build = [&](int p, int l, int r) {
		if (l == r) {
			Pos[l] = p;
			return Seg[p] = A[l];
		}
		int m = (l + r) / 2;
		return Seg[p] = build(2*p, l, m) ^ build(2*p+1, m+1, r);
	};
	build(1, 0, (1 << n) - 1);

	while (q--) {
		int idx, x; cin >> idx >> x;

		int u = Pos[idx - 1], res = 0;
		for (int i = 0; u != 1; i++) {
			int pai = u / 2, v = (2 * pai == u ? 2 * pai + 1 : 2 * pai);
			int ganhei = (x > Seg[v]) or (x == Seg[v] and u < v);
			u = pai;
			x ^= Seg[v];
			if (!ganhei) {
				res += (1 << i);
			}
		}
		cout << res << endl;
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

