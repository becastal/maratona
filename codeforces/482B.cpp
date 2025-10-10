#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e5+10;
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) & build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return INT_MAX;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) & query(a, b, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> A(n+1, vector<int>(31, 0));
	vector<tuple<int, int, int>> C(m);

	for (auto& [l, r, q] : C) {
		cin >> l >> r >> q; l--, r--;

		for (int k = 0; k < 30; k++) {
			if (!(q & (1 << k))) continue;

			A[l][k]++;
			A[r+1][k]--;
		}
	}

	vector<int> B(n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 30; k++) {
			if (i) A[i][k] += A[i-1][k];
			if (A[i][k]) B[i] |= (1 << k);
		}
	}

	seg::build(n, B.data());
	for (auto [l, r, q] : C) {
		if (seg::query(l, r) != q) return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl;
	for (int i : B) cout << i << ' '; cout << endl;

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
