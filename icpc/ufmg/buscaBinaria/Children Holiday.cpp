#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;
    
    int m, n; 
    cin >> m >> n;
    
    vector<tuple<int, int, int>> v(n);
    for (auto& [ti, zi, yi] : v) 
        cin >> ti >> zi >> yi;
    
    auto da = [&](int T) {
        ll tot = 0;
        for (auto [t, z, y] : v) {
            int cycle = t * z + y;
            int r = T % cycle;
            ll fullCycles = T / cycle;
            tot += fullCycles * z + min(z, r / t);
        }
        return tot >= m;
    };
    
    int l = 0, r = (int)1e9;  
    while (l < r) {
        int mi = (l + r) >> 1;
        if (da(mi)) {
            r = mi;
		} else {
            l = mi + 1;
		}
    }
    
    cout << l << endl;
    
    int rem = m;
    for (auto [t, z, y] : v) {
        int cycle = t * z + y;
        int cnt = (l / cycle) * z + min(z, (l % cycle) / t);
        int take = min(cnt, rem);
        cout << take << " ";
        rem -= take;
    }
    cout << endl;
    
    return(0);
}

