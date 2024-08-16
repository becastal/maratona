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
const int MOD = 998244353;

template<int mod>
struct modInt {
    unsigned x;
    modInt() : x(0) { }
    modInt(signed sig) : x((sig % mod + mod) % mod) { }
    modInt(signed long long sig) : x((sig % mod + mod) % mod) { }
    int get() const { return (int)x; }
    modInt pow(ll p) {
        modInt res = 1, a = *this;
        while (p) {
            if (p & 1) res *= a;
            a *= a; p >>= 1;
        }
        return res;
    }

    modInt& operator+=(modInt that) { if ((x += that.x) >= mod) x -= mod; return *this; }
    modInt& operator-=(modInt that) { if ((x += mod - that.x) >= mod) x -= mod; return *this; }
    modInt& operator*=(modInt that) { x = (unsigned long long)x * that.x % mod; return *this; }
    modInt& operator/=(modInt that) { return (*this) *= that.pow(mod - 2); }

    modInt operator+(modInt that) const { return modInt(*this) += that; }
    modInt operator-(modInt that) const { return modInt(*this) -= that; }
    modInt operator*(modInt that) const { return modInt(*this) *= that; }
    modInt operator/(modInt that) const { return modInt(*this) /= that; }
    bool operator<(modInt that) const { return x < that.x; }
    bool operator>(modInt that) const { return x > that.x; }
    friend ostream& operator<<(ostream& os, modInt a) { os << a.x; return os; }
    friend istream& operator>>(istream& is, modInt& a) { is >> a.x; return is; }
};
typedef modInt<MOD> mint;

struct nodo {
    mint a, b, ab;
};

namespace seg {
    nodo seg[4*MAX], lazy[4*MAX], v[MAX];
    int n;

    nodo combine(const nodo& a, const nodo& b) {
        nodo c;
        c.a = a.a + b.a;
        c.b = a.b + b.b;
        c.ab = a.ab + b.ab;
        return c;
    }

    nodo build(int p = 1, int l = 0, int r = n - 1) {
        lazy[p] = {mint(0), mint(0), mint(0)};
        if (l == r) return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = combine(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
    }

    void prop(int p, int l, int r) {
        if (lazy[p].a.x != 0 || lazy[p].b.x != 0) {
            seg[p].ab += lazy[p].a * seg[p].b + lazy[p].b * seg[p].a + lazy[p].a * lazy[p].b * (r - l + 1);
            seg[p].a += lazy[p].a * (r - l + 1);
            seg[p].b += lazy[p].b * (r - l + 1);

            if (l != r) {
                for (int child : {2 * p, 2 * p + 1}) {
                    lazy[child].a += lazy[p].a;
                    lazy[child].b += lazy[p].b;
                }
            }

            lazy[p] = {mint(0), mint(0), mint(0)};
        }
    }

    nodo query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l && r <= b) return seg[p];
        if (b < l || r < a) return {mint(0), mint(0), mint(0)};
        int m = (l + r) / 2;
        return combine(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
    }

    nodo update(int a, int b, nodo x, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l && r <= b) {
            lazy[p].a += x.a;
            lazy[p].b += x.b;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l || r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = combine(update(a, b, x, 2 * p, l, m), update(a, b, x, 2 * p + 1, m + 1, r));
    }
};

int main() {
    _;

    int n, q; cin >> n >> q; seg::n = n;
    for (int i = 0; i < n; i++) {
        cin >> seg::v[i].a;
    }
    for (int i = 0; i < n; i++) {
        cin >> seg::v[i].b;
        seg::v[i].ab = seg::v[i].a * seg::v[i].b;
    }

    seg::build();

    while (q--) {
        char tp; cin >> tp;
        int l, r, x;

        if (tp == '1') {
            cin >> l >> r >> x; l--, r--;
            nodo up;
            up.a = x;
            seg::update(l, r, up);
        } else if (tp == '2') {
            cin >> l >> r >> x; l--, r--;
            nodo up;
            up.b = x;
            seg::update(l, r, up);
        } else if (tp == '3') {
            cin >> l >> r; l--, r--;
            cout << seg::query(l, r).ab << endl;
        }
    }

    return 0;
}

