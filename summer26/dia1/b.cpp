#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 30050;
namespace seg {
	int seg[4*MAX], lazy[4*MAX];
	int n, *v;
	
	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l + r) / 2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) {
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
		lazy[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LLONG_MAX;
		int m = (l + r) / 2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l + r) / 2;
		return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

signed solve() {
	int n; cin >> n;
	string S; cin >> S;

	vector<int> C(2), V(n);
	for (int i = 0, p = 0; i < n; i++) {
		V[i] = (p += (S[i] == '(' ? +1 : -1));
		C[S[i] == ')']++;
	}

	seg::build(n, V.data());

	int q; cin >> q;
	while (q--) {
		int p; cin >> p;
		if (!p) {
			cout << (C[0] == C[1] and seg::query(0, n-1) >= 0 ? "YES" : "NO") << endl;
		} else {
			p--;
			C[S[p] == ')']--;
			C[S[p] != ')']++;
			seg::update(p, n-1, -2 * (S[p] == '(' ? +1 : -1));
			S[p] = (S[p] == ')' ? '(' : ')');

			//cout << S << endl;
			//for (int i = 0; i < n; i++) {
			//	cout << seg::query(i, i) << " \n"[i==n-1];
			//}
			//cout << (C[0] == C[1] and seg::query(0, n-1) >= 0 ? "YES" : "NO") << endl;
		}
	}

	return(0);
}

signed main()
{
    _;

	int t = 10; //cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Test " << i << ":" << endl;
		solve();
	}
    
    return(0);
}
