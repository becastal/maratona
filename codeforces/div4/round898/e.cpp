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

    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> v(n);
        for (int& i : v) cin >> i;
        auto vo = v; sort(vo.begin(), vo.end());

        function<ll(ll)> w = [&] (ll h) {
            ll res = 0;
            for (int i : v) {
                res += (h > i ? (ll) (h - i) : (ll) 0);
                if (res > x) return res;
            }
            return res;
        };

        ll l = 0, r = (ll) 1e14;
        while (l < r) {
            ll m = (l + r + 1) >> 1;
            if (w(m) <= x) 
                l = m;
            else
                r = m - 1;
        }
        
        cout << l << endl;
    }
    
    return 0;
}

