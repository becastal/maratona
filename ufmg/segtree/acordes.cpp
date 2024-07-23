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
    int seg[4 * MAX][9], int lazy[4 * MAX], int cont[9];
    int n;

    void build(int p = 1, int l = 0, int r = n - 1) {
        if (l == r) {
            seg[p][1] = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(2 * p, l, m), build(2 * p + 1, m + 1, r);
        seg[p][1] = r - l + 1;
    }

    void prop(int p, int l, int r) {
        if (!lazy[p]) return;
        int adi[9] = {0};
        for (int i = 0; i < 9; i++)
            adi[(i + lazy[p]) % 9] = seg[p][i];
        for (int i = 0; i < 9; i++)
            seg[p][i] = adi[i];

        if (l != r) {
            lazy[2 * p] = (lazy[2 * p] + lazy[p]) % 9;
            lazy[2 * p + 1] = (lazy[2 * p + 1] + lazy[p]) % 9;
        }
        lazy[p] = 0;
    }

    void query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l and r <= b) {
            for (int i = 0; i < 9; i++)
                cont[i] += seg[p][i];
            return;
        }
        if (b < l or r < a) return;
        int m = (l + r) >> 1;
        query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r);
    }

    void update(int a, int b, int x, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (b < l or r < a) return;
        if (a <= l and r <= b) {
            lazy[p] = x;
            prop(p, l, r);
            return;
        }

        int m = (l + r) >> 1;
        update(a, b, x, 2 * p, l, m), update(a, b, x, 2 * p + 1, m + 1, r);
        for (int i = 0; i < 9; i++)
            seg[p][i] = seg[2 * p][i] + seg[2 * p + 1][i];
    }
}

int main() {
    _;
    int q;
	cin >> seg::n >> q;
    seg::build();

    while (q--) {
        int l, r; cin >> l >> r;
        memset(seg::cont, 0, sizeof(seg::cont));
        seg::query(l, r);

        int val = 0;
        for (int i = 1; i < 9; i++)
            if (seg::cont[i] >= seg::cont[val]) val = i;

        seg::update(l, r, val);
    }

    for (int i = 0; i < seg::n; i++) {
        memset(seg::cont, 0, sizeof(seg::cont));
        seg::query(i, i);
        for (int j = 0; j < 9; j++)
            if (seg::cont[j]) {
				cout << j << endl;
                break;
            }
    }

    return 0;
}
