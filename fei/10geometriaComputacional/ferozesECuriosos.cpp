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

struct pt { // ponto
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
};

ld dist(pt p, pt q) { // distancia
    return hypot(p.y - q.y, p.x - q.x);
}

int n, aah;

bool solve()
{
    scanf("%d %d", &n, &aah);
    vector<pair<pt, int>> qs(n);

    for (auto& p : qs)
        scanf("%lf %lf %d", &p.f.x, &p.f.y, &p.s);

    for (int i = 0; i < n - 1; i++)
    {
        ld d = dist(qs[i].f, qs[i + 1].f);
        ld r1 = qs[i].s * sqrt(2) / 2, r2 = qs[i + 1].s * sqrt(2) / 2;

        if (d > r1 + r2 and d - (r1 + r2) > aah)
            return false;
    }
    return true;
}

int main()
{
    _;
    printf("%s\n", solve() ? "YEAH" : "OUCH");
    return 0;
}

