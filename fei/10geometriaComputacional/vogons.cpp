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

typedef double ld;
const ld DINF = 1e18;
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

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

bool isonseg(pt p, line r) { // se p pertence à reta de r
    pt a = r.p - p, b = r.q - p;
    return eq((a ^ b), 0);
}

bool isleft(pt p, line r) {
    return (r.q.x - r.p.x) * (p.y - r.p.y) - (r.q.y - r.p.y) * (p.x - r.p.x) > eps;
}

int main()
{
    _;
    line via;
    cin >> via;

    int n; cin >> n;
    
    int pOeste = 0, hOeste = 0;
    int pLeste = 0, hLeste = 0;
    int causalidades = 0;
    for (int i = 0; i < n; i++)
    {
        pt planeta; cin >> planeta;
        int h; cin >> h;
        if (isonseg(planeta, via))
            causalidades++;
        else if (isleft(planeta, via))
            pOeste++, hOeste += h;
        else
            pLeste++, hLeste += h;
    }
   
    cout << "Relatorio Vogon #35987-2" << endl;
    cout << "Distancia entre referencias: " << fixed << setprecision(2) << dist(via.p, via.q) << " anos-luz" << endl;
    cout << "Setor Oeste:\n- " << pOeste << " planeta(s)\n- " << hOeste << " bilhao(oes) de habitante(s)" << endl;
    cout << "Setor Leste:\n- " << pLeste << " planeta(s)\n- " << hLeste << " bilhao(oes) de habitante(s)" << endl;
    cout << "Casualidades: " << causalidades << " planeta(s)" << endl;
    return(0);
}
