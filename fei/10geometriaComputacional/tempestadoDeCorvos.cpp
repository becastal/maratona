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

int main()
{
    _;

    int xf, yf, xi, yi, vi, r1, r2;

    while (cin >> xf >> yf >> xi >> yi >> vi >> r1 >> r2)
    {
        double dist = sqrt(pow(xf - xi, 2) + pow(yf - yi, 2));
        dist += vi * 1.5;
        double alcance = r1 + r2;
        cout << (dist > alcance ? "N" : "Y") << endl; 
    }

    return(0);
}
