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

const int MAX = (int)2e5+20;
namespace seg {
	struct nodo {
		int mx, pos;
		nodo(int mx_ = -INF, int pos_ = -1) {
			mx = mx_, pos = pos_;
		}
	};
	nodo seg[4*MAX]; 
	int n, v[MAX];

	nodo combina (nodo a, nodo b) {
		return nodo(max(a.mx, b.mx), (a.mx >= b.mx ? a.pos : b.pos));
	};
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l], l);
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo();
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(x, i);
		int m = (l+r)/2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

namespace fen {
	int n;
	vector<int> bit;

	void build(int n_) {
		n = n_;
		bit.assign(n+10, 0);
	}
	void add(int i, int x) {
		for (++i; i < n; i += i&-i) {
			bit[i] += x;
		}
	}
	void update(int l, int r, int x) {
		add(l, x);
		add(r + 1, -x);
	}
	int query(int i) {
		int res = 0;
		for (++i; i > 0; i -= i&-i) {
			res += bit[i];
		}
		return res;
	}
}

int solve() {
	int n, m = 0, k; cin >> n >> k;
	seg::n = n;

	vector<int> res;
	vector<tuple<int, int, int>> v(n);

	int id_ = 0;
	for (auto& [a, b, id] : v) {
		cin >> a >> b; id = id_++;
		m = max(m, b);
	}

	fen::build(m+10);
	for (auto [a, b, id] : v) {
		fen::update(a, b, +1);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		auto [a, b, id] = v[i];
		seg::v[i] = b;
	}
	seg::build();

	for (int i = 0; i <= fen::n; i++) {
		while (fen::query(i) > k) {
			int r = upper_bound(v.begin(), v.end(), make_tuple(i, INF, INF)) - v.begin();
			auto qr = seg::query(0, r-1);
			
			auto [a, b, id] = v[qr.pos];
			res.push_back(id);
			fen::update(a, b, -1);
			seg::update(qr.pos, -INF);
		}
	}

	cout << res.size() << endl;
	for (int i : res) cout << i+1 << ' '; cout << endl;

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
