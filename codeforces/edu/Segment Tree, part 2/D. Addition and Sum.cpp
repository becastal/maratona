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

const int MAX = 100000;
namespace seg {
    ll seg[4*MAX], lazy[4*MAX];
    int n;

    void prop(int p, int l, int r) {
        if (lazy[p] != 0) {
            seg[p] += lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    void update(int a, int b, ll v, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
            lazy[p] += v;
            prop(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, v, 2*p, l, m);
        update(a, b, v, 2*p+1, m+1, r);
        seg[p] = seg[2*p] + seg[2*p+1];
    }

    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a > r || b < l) return 0;
        if (a <= l && r <= b) return seg[p];
        int m = (l + r) / 2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }
}

int main() {
    _;
    int m;
    cin >> seg::n >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            ll v;
            cin >> v;
            seg::update(l, r-1, v);
        } else {
            cout << seg::query(l, r-1) << endl;
        }
    }

    return 0;
}
