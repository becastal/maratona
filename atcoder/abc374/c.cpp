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

    int n; cin >> n;
    ll total = 0;
    vector<int> v(n);
    
    for (int& i : v) cin >> i, total += i;

    ll res = LINF;
    
    for (int i = 0; i < (1 << n); i++) {
        ll agr = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                agr += v[j];
            }
        }
        res = min(res, max(agr, total - agr));
    }

    cout << res << endl;
    
    return 0;
}

