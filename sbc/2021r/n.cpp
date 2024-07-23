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

namespace seg {
    vector<vector<int>> seg;
    int n, *v;

    void build(int p=1, int l=0, int r=n-1) {
        if (l == r) {
            seg[p].push_back(v[l]);
            return;
        }
        int m = (l+r)/2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        merge(seg[2*p].begin(), seg[2*p].end(), seg[2*p+1].begin(), seg[2*p+1].end(), back_inserter(seg[p]));
    }

    void build(int n2, int* v2) {
        n = n2, v = v2;
        seg.resize(4*n);
        build();
    }

    int query(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) {
            return lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin();
        }
        int m = (l+r)/2;
        return query(a, b, x, 2*p, l, m) + query(a, b, x, 2*p+1, m+1, r);
    }
};

int main() {
	_;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    seg::build(n, v.data());
    while (q--) {
        int a, p, f;
        cin >> a >> p >> f;
        a--;
        (v[a] >= p) ? cout << 0 << endl : cout << f - seg::query(a + 1, a + f, p) << endl;
    }
    return 0;
}

