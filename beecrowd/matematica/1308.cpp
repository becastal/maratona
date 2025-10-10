#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

    const ll lim = 2828427124;  

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        
        ll l = 1, r = lim;
        while (l < r) {
            ll m = (l + r) / 2;

            if (m * (m + 1) / 2 < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
		if (l * (l+1) / 2 > n) l--;
        cout << l << endl;
    }
    
    return 0;
}

