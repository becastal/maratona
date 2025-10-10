// #include "../../geodeb.h"
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

#define sq(x) ((x)*(x))
typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;


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

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld disttoline(pt p, line r) { // distancia do ponto a reta
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

ld disttoseg(pt p, line r) { // distancia do ponto ao seg
	if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
	return disttoline(p, r);
}

int main()
{
    _;
    // GD_INIT("_geo.html");
    
    int n;
    while (cin >> n)
    {
        int l, h; cin >> l >> h;
        line borda1(pt(0, 0), pt(0, h)), borda2(pt(l, 0), pt(l, h));
        // GD_SEGMENT(0, 0, 0, h);
        // GD_SEGMENT(l, 0, l, h);

        vector<line> aletas;
        for (int i = 0; i < n; i++)
        {
            int xi, yi, xf, yf; cin >> yi >> xf >> yf;
            xi = (i % 2 ? l : 0);

            line aleta(pt(xi, yi), pt(xf, yf));
            aletas.push_back(aleta);
            // GD_SEGMENT(xi, yi, xf, yf, "red");
        }

        ld menor = DINF;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                menor = min(menor, disttoseg(aletas[i].q, borda1));
                // GD_SEGMENT(aletas[i].q.x, aletas[i].q.y, borda1.q.x, aletas[i].q.y, "green");
            }
            else
            {
                menor = min(menor, disttoseg(aletas[i].q, borda2));
                // GD_SEGMENT(aletas[i].q.x, aletas[i].q.y, borda2.q.x, aletas[i].q.y, "green");
            }
            
            if (i < n - 1)
                menor = min(menor, disttoseg(aletas[i].q, aletas[i + 1]));
        }

        cout << fixed << setprecision(2) << menor << endl;
    }

    return(0);
}
