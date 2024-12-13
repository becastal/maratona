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
const int MAX = 1e5 + 10;
namespace seg {
    ll seg[4*MAX], lazy[4*MAX];
    int n;

    ll build(int p=1, int l=0, int r =n-1) {
        lazy[p] = -1;
        if (l == r) return seg[p] = 0;
        int m = (l + r) / 2;
        return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
    }

    void prop(int p, int l, int r) {
        if (lazy[p] != -1) {
            seg[p] = lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[2 * p] = lazy[p];
                lazy[2 * p + 1] = lazy[p];
            }
            lazy[p] = -1;
        }
    }

    ll query(int a, int b, int p=1, int l=0, int r =n-1) {
        prop(p, l, r);
        if (a <= l && r <= b) return seg[p];
        if (b < l || r < a) return 0;
        int m = (l + r) / 2;
        return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
    }

    ll update(int a, int b, int x, int p=1, int l=0, int r =n-1) {
        prop(p, l, r);
        if (a <= l && r <= b) {
            lazy[p] = x;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l || r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = update(a, b, x, 2 * p, l, m) + update(a, b, x, 2 * p + 1, m + 1, r);
    }
};

int main()
{
    _;

    int n, m; 
    cin >> n >> m; 
    seg::n = n;

    seg::build();	

    int turno = 0;
    for (int i = 0, l, d; i < m; i++) {
        cin >> l >> d;
        seg::update(l, l + d - 1, turno);
        turno ^= 1;
    }

    vector<int> cont(2, 0);
    for (int i = 0; i < n; i++) {
        int q = seg::query(i, i);
        //cout << q << " \n"[i == n - 1];
        if (q >= 0) cont[q]++;
    }

    if (cont[0] == cont[1]) return cout << "Empate" << endl, 0;
    cout << (cont[0] > cont[1] ? "Gabriela" : "Guilherme") << endl;

    return 0;
}

