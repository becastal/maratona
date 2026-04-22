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
    vector<ll> v(n);

    for (ll &ai : v)
        cin >> ai;

    ll c = 0;
    for (int l = 0; l < n; ++l)
    {
        ll r = l;
        while (r < n && v[r] == v[l])
            ++r;
        ll len = r - l;
        c += len * (len + 1) / 2;
        l = r - 1;
    }

    cout << c << endl;
    
    return(0);
}

