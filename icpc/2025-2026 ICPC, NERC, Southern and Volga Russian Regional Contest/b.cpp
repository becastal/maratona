#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int eq(ll a, ll b) {
	return a == b;
}

struct pt { // ponto
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ll c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ll c) const { return pt(x/c  , y/c  ); }
	ll operator * (const pt p) const { return x*p.x + y*p.y; }
	ll operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};


ll sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q));
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

int ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	if (col(p, q, r)) return 0;
	return sarea(p, q, r) > 0 ? 1 : 2;
}

int solve() {
	int n; cin >> n;
	vector<pt> A(n);

	for (auto& i : A) cin >> i;

	auto da = [&](int m) {
		vector<int> F(3, 0);

		for (int r = 2; r < n; r++) {
			F[ccw(A[r-2], A[r-1], A[r])]++;

			int l = r - m + 1;
			if (l >= 0) {
				if (l - 1 >= 0) F[ccw(A[l-1], A[l], A[l+1])]--;
				int a = ccw(A[r-1], A[r], A[l]), b = ccw(A[r], A[l], A[l+1]);
				F[a]++, F[b]++;

				if (!F[0] and !F[1] and F[2]) return 1;

				F[a]--, F[b]--;
			}
		}

		return 0;
	};

	int l = 3, r = n, res = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			l = m + 1;
			res = m;
		} else {
			r = m - 1;
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

