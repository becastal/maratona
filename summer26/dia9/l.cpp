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
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		seg[p] = lazy[p];
		if (l != r) lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
	int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_left(a, b, val, 2*p, l, m);
		if (x != -1) return x;
		return get_left(a, b, val, 2*p+1, m+1, r);
	}
	int get_right(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_right(a, b, val, 2*p+1, m+1, r);
		if (x != -1) return x;
		return get_right(a, b, val, 2*p, l, m);
	}
};

namespace segb {
	int seg[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		seg[p] = lazy[p];
		if (l != r) lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};


set<int> S[MAX];
signed solve() {
	int n; cin >> n;

	vector<int> A(n);
	for (int& i : A) cin >> i;

	set<int> SS, ja;
	for (int i = 0; i < n; i++) {
		S[A[i]].insert(i);
		SS.insert(i);
	}
	seg::build(n, A.data());
	
	int q; cin >> q;
	for (int t = q; t >= 1; t--) {
		int c; cin >> c;

		if (S[c].size() <= 1) continue;
		int l = *S[c].begin(), r = *S[c].rbegin();

		for (int p = l + 1; ; ) {
			p = *SS.lower_bound(p);
			if (p < r) {
				SS.erase(p);

				int c_ = seg::query(p, p);
				if (ja.count(c_)) {
					S[c_].erase(p);
					if (p == *S[c_].begin()) {
						S[c_].insert(r + 1);
					} else {
						S[c_].insert(l - 1);
					}
				} else {
					S[c_].erase(p);	
				}
				p++;
			} else break;
		}
		S[c].clear();
		S[c].insert(l), S[c].insert(r);
		seg::update(l, r, c);
	}

	for (int i = 0; i < n; i++) {
		cout << seg::query(i, i) << " \n"[i==n-1];
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
