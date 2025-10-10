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
 
const int MAX = 2e5 + 10;
 
namespace sparse {
    int t[MAX][18], v[MAX];
    int n;
 
    void build() {
        for(int i = 0; i < n; ++i) t[i][0] = v[i];
        for(int k = 1; (1 << k) <= n; ++k) {
            for(int i = 0; i + (1 << k) <= n; ++i) {
                t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
 
    int query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }
};
 
int main()
{
    _;
 
    int n, q; cin >> n >> q; sparse::n = n;
    for (int i = 0; i < n; i++) {
        cin >> sparse::v[i];
    }
 
    sparse::build();
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r; l--, r--;
        cout << sparse::query(l, r) << endl;    
    }
    
    return(0);
}
