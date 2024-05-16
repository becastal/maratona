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

bool cmpY(pt& a, pt& b)
{
    return a.y < b.y;
}

bool cmpX(pt& a, pt& b)
{
    return a.x < b.x;
}

ld solveFaixa(vector<pt>& faixa, ld d)
{
    ld minDist = d;

    sort(faixa.begin(), faixa.end(), cmpY);

    for (int i = 0; i < faixa.size(); i++)
        for (int j = i + 1; j < faixa.size() && (faixa[j].y - faixa[i].y) < minDist; j++)
            minDist = min(minDist, dist(faixa[i], faixa[j]));

    return minDist;
}

ld solve(vector<pt>& pts)
{
    int n = pts.size();
    
    if (n <= 1)
        return DINF;

    sort(pts.begin(), pts.end(), cmpX);

    int m = n / 2;
    vector<pt> e(pts.begin(), pts.begin() + m);
    vector<pt> d(pts.begin() + m, pts.end());

    ld minE = solve(e);
    ld minD = solve(d);

    ld minDist = min(minE, minD);

    vector<pt> faixa;
    ld midFaixa = pts[m].x;
    for (int i = 0; i < n; i++)
        if (abs(pts[i].x - midFaixa) < minDist)
            faixa.push_back(pts[i]);

    ld minFaixa = solveFaixa(faixa, minDist);
    return min(minDist, minFaixa);
}

int main()
{
    _;
    
    int n;
    while (cin >> n && n)
    {
        vector<pt> pts(n);
        for (auto& p : pts)
            cin >> p;

        ld resp = solve(pts);
        if (resp < 10000)
            cout << fixed << setprecision(4) << resp << endl;
        else
            cout << "INFINITY" << endl;
    }

    return(0);
}
