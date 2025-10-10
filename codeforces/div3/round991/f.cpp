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
	ll seg[4*MAX], v[MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = gcd(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return gcd(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

void solve() {
	int n, q; cin >> n >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	if (n == 1) {
		while (q--) {
			int l, r; cin >> l >> r;
			cout << 0 << ' ';
		}
		cout << endl;

		return;
	}

	vector<int> dif(n-1);
	for (int i = 1; i < n; i++) {
		dif[i-1] = abs(v[i]-v[i-1]);
	}

	seg::n = n-1;
	for (int i = 0; i < n-1; i++) {
		seg::v[i] = dif[i];
	}

	seg::build();
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		cout << (l == r ? 0 : seg::query(l, r-1)) << ' ';
	}
	cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
