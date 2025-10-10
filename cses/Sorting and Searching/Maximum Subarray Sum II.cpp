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
	ll seg[4*MAX], *v;
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n_, ll* v_) {
		n = n_, v = v_;
		build();
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return LINF;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return min(seg[p] = update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

int solve() {
	int n, a, b; cin >> n >> a >> b;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<ll> pre(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + A[i-1];
	}

	ll res = -LINF;
	seg::build(n+1, pre.data());
	for (int i = a; i <= n; i++) {
		res = max(res, pre[i] - seg::query(max(0, i - b), i - a));
	}
	cout << res << endl;

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
