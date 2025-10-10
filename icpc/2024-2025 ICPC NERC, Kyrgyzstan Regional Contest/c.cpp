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

// Geometria

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}


struct pt {
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

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

int solve() {
	int n; cin >> n;

	vector<pt> a(n);
	for (auto& i : a) cin >> i;

	for (int i = 0; i < 8; i++) {
		auto a_ = a;
		for (auto& j : a_) {
			j = rotate(j, (ld)i * (pi / 4.0));
		}

		int ok = 1;
		for (int j = 0; j < n-1 and ok; j++) {
			ok &= (a_[j].x < a_[j+1].x) or ((a_[j].x == a_[j+1].x) and a_[j].y < a_[j+1].y);
		}

		if (ok) {
			pt X(1.0, 0.0), Y(0.0, 1.0);
			X = rotate(X, (ld)i * (pi / 4.0));
			Y = rotate(Y, (ld)i * (pi / 4.0));
			cout << "YES" << endl;
			cout << round(X.x) << ' ' << round(X.y) << endl;	
			cout << round(Y.x) << ' ' << round(Y.y) << endl;	
			return 0;
		}
	}
	cout << "NO" << endl;

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
