#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
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
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

int inpol(vector<pt>& v, pt p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (eq(p.y, v[i].y) and eq(p.y, v[j].y)) {
			if ((v[i]-p)*(v[j]-p) < eps) return 2;
			continue;
		}
		bool baixo = v[i].y+eps < p.y;
		if (baixo == (v[j].y+eps < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (eq(t, 0)) return 2;
		if (baixo == (t > eps)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}


ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

ld dist(pt p, pt q) {
	return hypot(p.y - q.y, p.x - q.x);
}

ld disttoline(pt p, line r) {
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

ld disttoseg(pt p, line r) {
	if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
	return disttoline(p, r);
}

vector<pt> minkowski(vector<pt> p, vector<pt> q) {
	auto fix = [](vector<pt>& P) {
		rotate(P.begin(), min_element(P.begin(), P.end()), P.end());
		P.push_back(P[0]), P.push_back(P[1]);
	};
	fix(p), fix(q);
	vector<pt> ret;
	int i = 0, j = 0;
	while (i < p.size()-2 or j < q.size()-2) {
		ret.push_back(p[i] + q[j]);
		auto c = ((p[i+1] - p[i]) ^ (q[j+1] - q[j]));
		if (c >= 0) i = min<int>(i+1, p.size()-2);
		if (c <= 0) j = min<int>(j+1, q.size()-2);
	}
	return ret;
}

ld dist_convex(vector<pt> p, vector<pt> q) {
	for (pt& i : q) i = i * -1;
	auto s = minkowski(p, q);
	if (inpol(s, pt(0, 0))) return 0;
	ld ans = DINF;
	for (int i = 0; i < s.size(); i++) ans = min(ans,
			disttoseg(pt(0, 0), line(s[(i+1)%s.size()], s[i])));
	return ans;
}

ld rightmost_xaxis(const vector<pt>& s) {
	ld ans = -DINF;
	for (int i = 0; i < (int)s.size(); i++) {
		pt a = s[i], b = s[(i+1)%s.size()];

		if (eq(a.y, 0) and eq(b.y, 0)) {
			ans = max(ans, max(a.x, b.x));
			continue;
		}

		if ((a.y <= eps and b.y >= -eps) or (a.y >= -eps and b.y <= eps)) {
			if (eq(a.y, b.y)) continue;
			ld t = -a.y / (b.y - a.y);
			if (t >= -eps and t <= 1 + eps) {
				ld x = a.x + (b.x - a.x) * t;
				ans = max(ans, x);
			}
		}
	}
	return ans;
}

int solve() {
	cout << fixed << setprecision(3);
	int n; cin >> n;
	vector<vector<pt>> A(n);
	vector<ld> Mxx(n), Mnx(n);

	ld dhor = 0;
	for (int i = 0, m, x, y; i < n; i++) {
		cin >> m;
		A[i] = vector<pt>(m);
		ld mnx = DINF, mxx = -DINF;
		for (auto& p : A[i]) {
			cin >> x >> y;
			p.x = x, p.y = y;
			mxx = max(mxx, p.x);
			mnx = min(mnx, p.x);
		}
		dhor += (mxx - mnx);
		Mxx[i] = mxx, Mnx[i] = mnx;
	}

	auto B = A;
	for (auto& v : B) {
		for (pt& p : v) {
			p = p * -1;
		}
	}

	vector<vector<ld>> D(n, vector<ld>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {


			D[i][j] = Mxx[i] - Mnx[j] - rightmost_xaxis(minkowski(A[i], B[j]));
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << "D[" << i << "][" << j << "]: " << D[i][j] << endl;
	//	}
	//}

	vector<vector<ld>> Dp(1 << n, vector<ld>(n, -DINF));
	for (int u = 0; u < n; u++) {
		Dp[1 << u][u] = 0;
	}

	for (int mask = 0; mask < (1 << n); mask++) {
		for (int u = 0; u < n; u++) if (mask >> u & 1) {
			for (int v = 0; v < n; v++) if ((mask >> v & 1) ^ 1) {
				int mask_ = mask | (1 << v);
				Dp[mask_][v] = max(Dp[mask_][v], Dp[mask][u] + D[u][v]);
			}
		}
	}
	
	ld res = -DINF;
	for (int u = 0; u < n; u++) {
		res = max(res, Dp[(1 << n) - 1][u]);
	}

	cout << dhor - res << endl;
	
	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

