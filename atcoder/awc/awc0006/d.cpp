#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 3e5+10;
namespace seg {
	int seg[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {

	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LLONG_MAX;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			seg[p] = x;
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<int> C = {n, 0};
	vector<array<int, 2>> A(m);
	for (auto& [l, r] : A) {
		cin >> l >> r;
		C.push_back(l - 1);
		C.push_back(r);
	}

	sort(all(C));
	C.erase(unique(all(C)), C.end());
	int nn = (int)C.size();
	vector<vector<int>> L(nn);

	for (auto& [l, r] : A) {
		l = lower_bound(all(C), l - 1) - C.begin();
		r = lower_bound(all(C), r) - C.begin();
		L[r].push_back(l);
	}

	vector<int> dp(nn, LLONG_MAX);
	dp[0] = 0;

	seg::build(nn, dp.data());
	for (int i = 0; i < nn; i++) {
		for (int l : L[i]) {
			int w = seg::query(l, i);
			if (w == LLONG_MAX) continue;
			dp[i] = min(dp[i], w + 1);
		}
		seg::update(i, i, dp[i]);
	}
	
	int res = dp.back();
	cout << (res != LLONG_MAX ? res : -1) << endl;

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

