#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 40050;
namespace seg {
	int seg[4*MAX], lazy[4*MAX];
	int n, *v;
	
	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l + r) / 2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		seg[p] = lazy[p];
		if (l != r) {
			lazy[2*p] = lazy[p];
			lazy[2*p+1] = lazy[p];
		}
		lazy[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l + r) / 2;
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
		int m = (l + r) / 2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
}

signed solve() {
	int n; cin >> n;

	vector<int> V(n, 0);

	vector<int> B;
	vector<array<int, 2>> Q(n);
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		Q[i] = {a, b};
		B.push_back(a);
		B.push_back(b);
	}
	sort(all(B));
	B.erase(unique(all(B)), B.end());
	int m = B.size();

	for (auto& [a, b] : Q) {
		a = lower_bound(all(B), a) - B.begin();
		b = lower_bound(all(B), b) - B.begin();
	}

	seg::build(m, V.data());
	for (int i = 0; i < n; i++) {
		seg::update(Q[i][0], Q[i][1], i + 1);
	}

	vector<int> A(m);
	for (int i = 0; i < m; i++) {
		A[i] = seg::query(i, i);		
		//cout << A[i] << " \n"[i==m-1];
	}

	set<int> S(all(A));
	S.erase(0);
	cout << int(S.size()) << endl;

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
