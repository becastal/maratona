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

const int MAX = 2e5+10;
namespace seg {
	ll seg[4*MAX], A[4*MAX], B[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		A[p] = B[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (!A[p] and !B[p]) return;

		ll tam = r - l + 1;
		seg[p] += (A[p] * (l + r) * tam / 2) + (B[p] * tam);
		if (l != r) {
			A[2*p] += A[p];
			A[2*p+1] += A[p];
			B[2*p] += B[p];
			B[2*p+1] += B[p];
		}
		A[p] = B[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			A[p]++, B[p] += 1 - a;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, 2*p, l, m) + update(a, b, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	seg::build(n, A.data());
	while (q--) {
		int tp, l, r; cin >> tp >> l >> r; l--, r--;

		if (tp == 1) {
			seg::update(l, r);	
		} else {
			cout << seg::query(l, r) << endl;
		}
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
