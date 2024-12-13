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

    int n, W; cin >> n >> W;

    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].s >> v[i].f;
    }

    sort(v.begin(), v.end(), [] (pair<double, double> a, pair<double, double> b) {
        return (a.f / a.s) > (b.f / b.s);
    });

    double res = 0.0;
    for (int i = 0; i < n; i++) {
        if (W == 0) break;

        if (v[i].s <= W) {
            res += v[i].f;
            W -= v[i].s;
        } else {
            res += (v[i].f / v[i].s) * W;
            W = 0;
        }
    }

    cout << fixed << setprecision(2) << res << endl;

    return 0;
}

