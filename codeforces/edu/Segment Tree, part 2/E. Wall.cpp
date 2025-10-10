#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define aint(x) (x).begin(), (x).end()
#define raint(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 2000020;
namespace beats {
	struct node {
		int tam;
		int sum, lazy; // lazy pra soma
		int mi1, mi2, mi; // mi = #mi1
		int ma1, ma2, ma; // ma = #ma1

		node(int x = 0) {
			sum = mi1 = ma1 = x;
			mi2 = INF, ma2 = -INF;
			mi = ma = tam = 1;
			lazy = 0;
		}
		node(const node& l, const node& r) {
			sum = l.sum + r.sum, tam = l.tam + r.tam;
			lazy = 0;
			if (l.mi1 > r.mi1) {
				mi1 = r.mi1, mi = r.mi;
				mi2 = min(l.mi1, r.mi2);
			} else if (l.mi1 < r.mi1) {
				mi1 = l.mi1, mi = l.mi;
				mi2 = min(r.mi1, l.mi2);
			} else {
				mi1 = l.mi1, mi = l.mi+r.mi;
				mi2 = min(l.mi2, r.mi2);
			}
			if (l.ma1 < r.ma1) {
				ma1 = r.ma1, ma = r.ma;
				ma2 = max(l.ma1, r.ma2);
			} else if (l.ma1 > r.ma1) {
				ma1 = l.ma1, ma = l.ma;
				ma2 = max(r.ma1, l.ma2);
			} else {
				ma1 = l.ma1, ma = l.ma+r.ma;
				ma2 = max(l.ma2, r.ma2);
			}
		}
		void setmin(int x) {
			if (x >= ma1) return;
			sum += (x - ma1)*ma;
			if (mi1 == ma1) mi1 = x;
			if (mi2 == ma1) mi2 = x;
			ma1 = x;
		}
		void setmax(int x) {
			if (x <= mi1) return;
			sum += (x - mi1)*mi;
			if (ma1 == mi1) ma1 = x;
			if (ma2 == mi1) ma2 = x;
			mi1 = x;
		}
		void setsum(int x) {
			mi1 += x, mi2 += x, ma1 += x, ma2 += x;
			sum += x*tam;
			lazy += x;
		}
	};

	node seg[4*MAX];
	int n, *v;

	node build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l]};
		int m = (l+r)/2;
		return seg[p] = {build(2*p, l, m), build(2*p+1, m+1, r)};
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (l == r) return;
		for (int k = 0; k < 2; k++) {
			if (seg[p].lazy) seg[2*p+k].setsum(seg[p].lazy);
			seg[2*p+k].setmin(seg[p].ma1);
			seg[2*p+k].setmax(seg[p].mi1);
		}
		seg[p].lazy = 0;
	}
	pair<pair<int, int>, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return {{INF, -INF}, 0};
		if (a <= l and r <= b) return {{seg[p].mi1, seg[p].ma1}, seg[p].sum};
		prop(p, l, r);
		int m = (l+r)/2;
		auto L = query(a, b, 2*p, l, m), R = query(a, b, 2*p+1, m+1, r);
		return {{min(L.f.f, R.f.f), max(L.f.s, R.f.s)}, L.s+R.s};
	}
	node updatemin(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p].ma1 <= x) return seg[p];
		if (a <= l and r <= b and seg[p].ma2 < x) {
			seg[p].setmin(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatemin(a, b, x, 2*p, l, m),
						updatemin(a, b, x, 2*p+1, m+1, r)};
	}
	node updatemax(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p].mi1 >= x) return seg[p];
		if (a <= l and r <= b and seg[p].mi2 > x) {
			seg[p].setmax(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatemax(a, b, x, 2*p, l, m),
						updatemax(a, b, x, 2*p+1, m+1, r)};
	}
	node updatesum(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p].setsum(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatesum(a, b, x, 2*p, l, m),
						updatesum(a, b, x, 2*p+1, m+1, r)};
	}
};

int solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n, 0);
	beats::build(n, A.data());

	while (k--) {
		int tp, l, r, h; cin >> tp >> l >> r >> h;

		if (tp == 1) beats::updatemax(l, r, h);
		else beats::updatemin(l, r, h);
	}

	for (int i = 0; i < n; i++) {
		cout << beats::query(i, i).f.f << endl;
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
