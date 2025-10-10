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
    
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    
    vector<ll> ga, ba;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) ga.push_back(a[i]);
        else ba.push_back(a[i]);
    }
    
    vector<ll> gb;
    for (int i = 0; i < m; i++) {
        if (b[i] > 0) gb.push_back(b[i]);
    }
    
    sort(ga.rbegin(), ga.rend());
    sort(ba.rbegin(), ba.rend());
    sort(gb.rbegin(), gb.rend());
    
    ll res = 0;
    for (ll x : ga) res += x;
    
    for (int i = 0; i < min((int)ga.size(), (int)gb.size()); i++) {
        res += gb[i];
    }
    
    int extra = gb.size() - (int)ga.size();
    for (int i = 0; i < extra; i++) {
        if (i < (int)ba.size()) {
            ll agr = gb[(int)ga.size() + i] + ba[i];
            if (agr > 0) res += agr;
            else break;
        }
        else break;
    }
    
    cout << res << endl;
    return(0);
}
