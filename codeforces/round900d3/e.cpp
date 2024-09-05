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

namespace seg {
    int seg[4*MAX], v[MAX];
    int n;

    int build(int p=1, int l=0, int r=n-1) {
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) & build(2*p+1, m+1, r);
    }
    int query(int a, int b, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return INT_MAX;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) & query(a, b, 2*p+1, m+1, r);
    }
};

void solve() {
	int n; cin >> n; seg::n = n;
    for (int i = 0; i < n; i++) {
        cin >> seg::v[i];
    }
    seg::build();    

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, k; cin >> l >> k; l--;
        
        int lb = l, rb = n - 1;
        while (lb < rb) {
            int m = (lb+rb+1) / 2;

            if (seg::query(l, m) < k) {
                rb = m - 1;
            } else {
                lb = m;
            }
        }
        
        int res = (seg::query(l, rb) < k ? -1 : rb+1);
        cout << res << ' ';
    }
    cout << endl;
}

int main()
{
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
    return(0);
}

