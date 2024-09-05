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
const ld pi = acos(-1.0);

int main()
{
    _;

    int s, a; 
    string tp;
    while (cin >> s >> a >> tp) {
        ld r = s + 6440.0;

        ld ang = a * pi / 180.0;
		if (tp == "min") ang /= 60.0;

        ld arco = r * ang;
        ld dist = sqrt(2*r*r*(1-cos(ang)));

        cout << fixed << setprecision(6);
        cout << arco << ' ' << dist << endl;
    }
    
    return 0;
}

