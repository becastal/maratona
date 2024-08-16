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
    ll seg[4 * MAX], lazyAdd[4 * MAX], lazyAssign[4 * MAX];
    int v[MAX];
    int n;

    ll build(int p = 1, int l = 0, int r = n - 1) {
        lazyAdd[p] = 0;
        lazyAssign[p] = LINF;
        if (l == r) return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
    }

    void prop(int p, int l, int r) {
        if (lazyAssign[p] != LINF) {
            seg[p] = lazyAssign[p] * (r - l + 1);
            if (l != r) {
                lazyAssign[2 * p] = lazyAssign[p];
                lazyAssign[2 * p + 1] = lazyAssign[p];
                lazyAdd[2 * p] = lazyAdd[2 * p + 1] = 0;
            }
            lazyAssign[p] = LINF;
        }

        if (lazyAdd[p] != 0) {
            seg[p] += lazyAdd[p] * (r - l + 1);
            if (l != r) {
                if (lazyAssign[2 * p] == LINF) lazyAdd[2 * p] += lazyAdd[p];
                else lazyAssign[2 * p] += lazyAdd[p];

                if (lazyAssign[2 * p + 1] == LINF) lazyAdd[2 * p + 1] += lazyAdd[p];
                else lazyAssign[2 * p + 1] += lazyAdd[p];
            }
            lazyAdd[p] = 0;
        }
    }

    ll query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l && r <= b) return seg[p];
        if (b < l || r < a) return 0;
        int m = (l + r) / 2;
        return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
    }

    ll update(int a, int b, int x, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l && r <= b) {
            lazyAdd[p] += x;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l || r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = update(a, b, x, 2 * p, l, m) + update(a, b, x, 2 * p + 1, m + 1, r);
    }

    ll assign(int a, int b, int x, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l && r <= b) {
            lazyAssign[p] = x;
            lazyAdd[p] = 0;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l || r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = assign(a, b, x, 2 * p, l, m) + assign(a, b, x, 2 * p + 1, m + 1, r);
    }
};

int main() {
    _;

    int n, q; 
    cin >> n >> q; 
    seg::n = n;

    for (int i = 0; i < n; i++) {
        cin >> seg::v[i];
    }

    seg::build();
    while (q--) {
        char tp; cin >> tp;
        int a, b, x;

        if (tp == '1') {
            cin >> a >> b >> x; a--, b--;
            seg::update(a, b, x);    
        } else if (tp == '2') {
            cin >> a >> b >> x; a--, b--;
            seg::assign(a, b, x);    
        } else if (tp == '3') {
            cin >> a >> b; a--, b--;
            cout << seg::query(a, b) << endl;
        }
    }

    return 0;
}
