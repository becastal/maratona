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

const int MAX = 4e5+50;
namespace seg {
	int seg[4*MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] += x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n; cin >> n;

	vector<int> L(n), R(n), e;
	vector<tuple<int, int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> L[i] >> R[i];
		a[i] = {L[i], R[i], i};
		e.push_back(L[i]);
		e.push_back(R[i]);
	}
	
	sort(a.begin(), a.end());
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());

	auto id = [&](int x) {
		return lower_bound(e.begin(), e.end(), x) - e.begin();
	};

	seg::n = (int)e.size();

	seg::build();
	vector<int> resa(n, 0);
	sort(a.begin(), a.end(), [&](tuple<int, int, int> i, tuple<int, int, int> j) {
		auto [li, ri, ii] = i;
		auto [lj, rj, jj] = j;

		if (li != lj) return li > lj;
		return ri < rj;
	});
	for (int i = 0; i < n; i++) {
		auto [l, r, pos] = a[i];
		l = id(l), r = id(r);
		resa[pos] = seg::query(0, r);
		seg::update(r, +1);
	}

	seg::build();
	vector<int> resb(n);
	sort(a.begin(), a.end(), [&](tuple<int, int, int> i, tuple<int, int, int> j) {
		auto [li, ri, ii] = i;
		auto [lj, rj, jj] = j;

		if (li != lj) return li < lj;
		return ri > rj;
	});
	for (int i = 0; i < n; i++) {
		auto [l, r, pos] = a[i];
		l = id(l), r = id(r);
		resb[pos] = seg::query(r, seg::n-1);
		seg::update(r, +1);
	}

	for (auto v : {resa, resb}) {
		for (int i : v) cout << !!i << ' '; cout << endl;
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
