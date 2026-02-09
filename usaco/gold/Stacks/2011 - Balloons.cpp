#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

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

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

int solve() {
	int n; cin >> n;
	vector<array<ld, 2>> A(n);

	for (auto& [x, r] : A) {
		cin >> x >> r;
	}

	vector<ld> R(n);

	auto toca = [&](ld xj, ld rj, ld xi) {
		ld dx = (xi - xj); 
		return sq(dx) / (4.0 * rj);
	};

	stack<int> S;
	for (int i = 0; i < n; i++) {
		ld rr = A[i][1];

		while (S.size()) {
			int j = S.top();
			ld agr = toca(A[j][0], R[j], A[i][0]);
			rr = min(rr, agr);
			
			if (rr >= R[j]) {
				S.pop();
			} else {
				break;
			}
		}

		R[i] = rr;
		S.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(10) << R[i] << "\n";
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

