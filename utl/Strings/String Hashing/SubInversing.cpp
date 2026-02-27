#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 2e5+10, UPD = 2e5+10, LOG = 18;
const int MAXS = 2*MAX+UPD*LOG;

namespace perseg {
	int seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n, *v;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = v[l];
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) ^ build(R[p], m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) ^ query(a, b, R[p], m+1, r);
	}
	int query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	int update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = seg[lp]^x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) ^ seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] ^ update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int solve() {
	int n, q; cin >> n >> q;

	vector<int> init(n + 1, 0);
	perseg::build(n+1, init.data());

	int melhor = 0;
	vector<array<int, 2>> Q(q);
	for (auto& [a, b] : Q) {
		cin >> a >> b; a--, b--;
	}

	for (int i = 0; i < q; i++) {
		auto [a, b] = Q[i];
		perseg::update(a, 1);
		perseg::update(b + 1, 1);

		if (i) {
			int l = 0, r = n, pos = 0;
			while (l <= r) {
				int m = l + (r - l) / 2;

				if (perseg::query(0, m, 2 * melhor + 1) != perseg::query(0, m, 2 * i + 1)) {
					r = m - 1;
				} else {
					l = m + 1;	
					pos = m;
				}
			}
			if (pos == n) continue;

			int antes = perseg::query(0, pos, 2 * melhor + 1), depois = perseg::query(0, pos, 2 * i + 1);
			if (depois > antes) {
				melhor = i;	
			}
		}
	}

	vector<int> res(n + 1, 0);
	for (int i = 0; i <= melhor; i++) {
		auto [a, b] = Q[i];
		res[a] ^= 1, res[b + 1] ^= 1;
	}

	for (int i = 0, p = 0; i < n; i++) {
		p ^= res[i];
		cout << p;
	}
	cout << endl;

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

