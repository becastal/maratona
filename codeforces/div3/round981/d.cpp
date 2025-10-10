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

void solve() {
    int n; 
    cin >> n;
    vector<ll> v(n), pre(n+1, 0);
    
    for (ll &i : v) cin >> i;
    
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + v[i-1];  
    }

    int res = 0, ult = 0;
    map<ll, int> M;
    M[0] = 0;

    for (int r = 1; r <= n; r++) {
        if (M.count(pre[r])) {
            int l = M[pre[r]];
            if (l >= ult) { 
                res++;
                ult = r;
            }
        }
        M[pre[r]] = r;
    }

    cout << res << endl;
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
}

