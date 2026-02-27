#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l = 0, r = 0; // children indices
    int sum = 0;      // XOR parity over this segment (0/1)
};

static const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> vals;
    vals.reserve(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    // Coordinate compress values (sorted by actual value)
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();

    // Persistent segment tree storage
    vector<Node> seg;
    seg.reserve((n + 5) * 20);
    seg.push_back(Node{}); // node 0 = null node (all zeros)

    auto newNode = [&](int lc, int rc, int sum) {
        seg.push_back(Node{lc, rc, sum});
        return (int)seg.size() - 1;
    };

    function<int(int,int,int,int)> update = [&](int prev, int tl, int tr, int pos) -> int {
        if (tl == tr) {
            return newNode(0, 0, seg[prev].sum ^ 1); // toggle leaf
        }
        int tm = (tl + tr) >> 1;
        int lc = seg[prev].l, rc = seg[prev].r;
        if (pos <= tm) lc = update(lc, tl, tm, pos);
        else rc = update(rc, tm + 1, tr, pos);
        int s = seg[lc].sum ^ seg[rc].sum;
        return newNode(lc, rc, s);
    };

    function<int(int,int,int,int)> firstDiff = [&](int u, int v, int tl, int tr) -> int {
        if ( (seg[u].sum ^ seg[v].sum) == 0 ) return INF; // no odd values here
        if (tl == tr) return tl;
        int tm = (tl + tr) >> 1;
        int ul = seg[u].l, ur = seg[u].r;
        int vl = seg[v].l, vr = seg[v].r;
        if ( (seg[ul].sum ^ seg[vl].sum) != 0 ) return firstDiff(ul, vl, tl, tm);
        return firstDiff(ur, vr, tm + 1, tr);
    };

    // Build roots for each prefix
    vector<int> root(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int idx = int(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1; // 1..m
        root[i] = update(root[i - 1], 1, m, idx);
    }

    int q;
    cin >> q;
    long long ansPrev = 0;

    while (q--) {
        long long A, B;
        cin >> A >> B;
        int l = int(A ^ ansPrev);
        int r = int(B ^ ansPrev);

        int idx = firstDiff(root[r], root[l - 1], 1, m);
        long long ans = 0;
        if (idx != INF) ans = vals[idx - 1];

        cout << ans << "\n";
        ansPrev = ans;
    }

    return 0;
}
