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
    while (t--)
    {
        ll n; cin >> n;
        vector<ll> v(n);
        
        for (auto& vi : v)
            cin >> vi;

        map<ll, vector<ll>> mp;
        for (auto vi : v)
            mp[vi/4].push_back(vi);

        for (auto [x, y] : mp)
            sort(mp[x].begin(), mp[x].end());

        map<ll, ll> qp;
        for (auto vi : v)
        {
            cout << mp[vi/4][qp[vi/4]] << " ";
            qp[vi/4]++;
        }
        cout << endl;

    }

    return(0);
}
