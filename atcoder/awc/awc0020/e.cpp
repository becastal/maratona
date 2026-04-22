#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 2e5+10;
namespace seg {
	int seg[4*MAX], n, *v;
	
	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l + r) / 2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n_, int *v_) {
		n = n_, v = v_;
		build();
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or a > r) return LLONG_MAX;
		if (a <= l and r <= b) return seg[p];
		int m = (l + r) / 2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (r < a or l > a) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l + r) / 2;
		return seg[p] = min(update(a, x, 2*p, l, m), update(a, x, 2*p+1, m+1, r));
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<int> W(n), C(m);
	for (int& i : W) {
		cin >> i;
	}
	for (int& i : C) {
		cin >> i;
	}
	vector<int> P(m);
	iota(all(P), 0);
	sort(all(P), [&](int a, int b) {
		return C[a] < C[b];
	});
	seg::build(m, P.data());
	vector<int> P_(m);
	for (int i = 0; i < m; i++) {
		P_[P[i]] = i;
	}
	sort(all(C));

	int res = 0;
	for (int i : W) {
		auto it = lower_bound(all(C), i);
		if (it == C.end()) continue;

		int pos = it - C.begin();
		int qual = seg::query(pos, m-1);

		if (qual != LLONG_MAX) {
			res++;
			seg::update(P_[qual], LLONG_MAX);
		}
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


