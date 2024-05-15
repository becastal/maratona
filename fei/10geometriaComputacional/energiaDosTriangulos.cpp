#include <bits/stdc++.h>
#include "../../geodeb.h"
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

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

int inpol(vector<pt>& v, pt p) { 
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

bool intri(pt& a, pt& b, pt& c, pt& p)
{
    ld s1 = abs(sarea(a, b, p));
    ld s2 = abs(sarea(b, c, p));
    ld s3 = abs(sarea(c, a, p));
    ld s = abs(sarea(a, b, c));

    return eq(s, s1 + s2 + s3);
}

int main()
{
    _;
    GD_INIT("_geo.html");
    int n, m;
    while (cin >> n >> m)
    {
        vector<pt> pretos(n);
        vector<pt> brancos(m);
        int k = 0;
        
        for (auto& p : pretos)
        {
            GD_POINT(p.x, p.y, "black");
            cin >> p;
        }
        for (auto& b : brancos)
        {
            GD_POINT(b.x, b.y, "grey");
            cin >> b;
        }

        int resp = 0;
        vector<vector<pt>> triangulos;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int l = j + 1; l < n; l++)
                {
                    int k = 0;
                    GD_TRIANGLE(pretos[i].x, pretos[i].y, pretos[j].x, pretos[j].y, pretos[l].x, pretos[l].y);
                    for (auto b : brancos)
                        if(intri(pretos[i], pretos[j], pretos[l], b))                        
                            k++;
                    resp += k * k;
                }
            
        cout << resp << endl;
    }
    return(0);
}
