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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 2e5+10;
namespace seg {
	ll seg[4*MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n; cin >> n; seg::n = 2*n;
	vector<int> A(2*n), res(n, n-1), L(n, -1), R(n);
	for (int& i : A) cin >> i, i--;
	seg::build();

	ordered_set ost;
	for (int i = 0; i < 2*n; i++) {
		if (L[A[i]] == -1) {
			L[A[i]] = i;
			ost.insert(i);
		} else {
			res[A[i]] -= seg::query(L[A[i]], i);
			res[A[i]] -= ost.order_of_key(L[A[i]]);

			seg::update(L[A[i]], 1);
			ost.erase(L[A[i]]);
			R[A[i]] = i;
		}
	}

	auto L_ = L, R_ = R;
	sort(L_.begin(), L_.end());
	sort(R_.begin(), R_.end());
	for (int i = 0; i < n; i++) {
		res[i] -= (n - int(upper_bound(L_.begin(), L_.end(), R[i]) - L_.begin()));
		res[i] -= int(lower_bound(R_.begin(), R_.end(), L[i]) - R_.begin());
	}

	for (int i : res) cout << i << ' '; cout << endl;

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
