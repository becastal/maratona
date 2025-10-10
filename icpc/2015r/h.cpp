#include <bits/stdc++.h>
// #include "../../geodeb.h"
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
const ld DINF = 1e18; const ld pi = acos(-1.0);
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

int main()
{
    _;

    //GD_INIT("_geo.html");
    int n; cin >> n;
    vector<pt> pts(n);
    
    for (auto& p : pts)
    {
        cin >> p;
        // //GD_POINT(p.x, p.y, "red");
    }

    sort(pts.begin(), pts.end());
    
    int resp = 0;
    for (int i = 0; i < n; i++)
    {
        int abaixo = INF, acima = INF;
        for (int j = i + 1; j < n; j++)
        {
            if (pts[i].y == pts[j].y) 
                continue;
                
            if (pts[i].y < pts[j].y && abs(pts[i].y - pts[j].y) < abaixo)
            {
                abaixo = abs(pts[i].y - pts[j].y);
                resp++;
                // GD_RECT(pts[i].x, pts[i].y, pts[j].x, pts[j].y);
            }
            else if (pts[i].y > pts[j].y && abs(pts[i].y - pts[j].y) < acima)
            {
                acima = abs(pts[i].y - pts[j].y);
                resp++;
                // GD_RECT(pts[i].x, pts[i].y, pts[j].x, pts[j].y);
            }
        }
    }

    cout << resp << endl;
    return(0);
}

