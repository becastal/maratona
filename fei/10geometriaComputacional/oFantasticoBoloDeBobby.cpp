#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef double ld;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld DINF = 1e18;
const double INFd = std::numeric_limits<double>::infinity();
using namespace std;

// https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Primitivas/geometria.cpp

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

ld disttoseg(pt p, line r) { // distancia do ponto ao seg
	if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
	return disttoline(p, r);
}

int main()
{
    _;
    
    int n;
    while (cin >> n && n != 0)
    {
        vector<pt> p(n);
        for (auto& pi : p)
            cin >> pi.x >> pi.y;

        ld menor = -DINF;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                
                double somaE = 0, somaD = 0;
                if (p[i].f != p[j].f) // caso em que a reta p[i] -> p[j]  nao eh perpendicular ao eixo x
                {
                    double m = (p[i].s - p[j].s) / (p[i].f - p[j].f); // coeficiente angular da reta
                    double off = m * (-p[i].f) + p[i].s;              // termo b da formua y = ax + b

                    for (auto pi : p)
                    {
                        double d = (abs(m * pi.f - pi.s + off)) / (sqrt(pow(m, 2) + 1));
                        // d eh a distancia do ponto pi ate a reta y = m(x) + off
                        if (pi.s > pi.f * m + off) 
                            somaE += d;
                        else
                            somaD += d;
                    }
                }
                else
                {
                    double x = p[i].f;

                    for (auto pi : p)
                    {
                        double d = abs(x - pi.f);
                        if (pi.f < x)
                            somaE += d;
                        else
                            somaD += d;
                    }
                }
                menor = min(menor, abs(somaE - somaD)); 
            }
       cout << fixed << setprecision(3) << menor << endl; 
    }
    
    return(0);
}
