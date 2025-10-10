#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long mn = (long long)4e18;  // +inf
    long long mx = (long long)-4e18; // -inf
    long long bestD = 0;             // max absolute drawdown in segment
    long long num = 0, den = 1;      // best percentage drawdown as fraction num/den
};

// Compare a/b vs c/d (all non-negative), return true if a/b < c/d
static inline bool fracLess(long long a, long long b, long long c, long long d) {
    __int128 L = (__int128)a * d;
    __int128 R = (__int128)c * b;
    return L < R;
}

// Pick max of two fractions (num/den) by value
static inline pair<long long,long long> maxFrac(long long a, long long b, long long c, long long d) {
    return fracLess(a,b,c,d) ? make_pair(c,d) : make_pair(a,b);
}

struct SegTree {
    int n;
    vector<Node> st;

    SegTree(const vector<long long>& a) {
        n = (int)a.size();
        st.resize(4*n);
        build(1,0,n-1,a);
    }

    static Node merge(const Node& L, const Node& R) {
        if (L.mn == (long long)4e18) return R; // identity
        if (R.mn == (long long)4e18) return L; // identity

        Node res;
        res.mn = min(L.mn, R.mn);
        res.mx = max(L.mx, R.mx);

        // absolute drawdown
        long long crossD = L.mx - R.mn; // >= 0 because prices are positive; if negative, max with L/R handles it
        res.bestD = max({L.bestD, R.bestD, crossD});

        // percentage drawdown as fraction
        // candidates: L.num/L.den, R.num/R.den, cross = (L.mx - R.mn) / L.mx
        long long cnum = 0, cden = 1;
        if (L.mx > 0) { // prices are positive; just in case
            cnum = max(0LL, L.mx - R.mn);
            cden = L.mx;
        }
        auto bestLR = maxFrac(L.num, L.den, R.num, R.den);
        auto bestAll = maxFrac(bestLR.first, bestLR.second, cnum, cden);
        res.num = bestAll.first;
        res.den = bestAll.second;

        return res;
    }

    void build(int p, int l, int r, const vector<long long>& a) {
        if (l == r) {
            st[p].mn = st[p].mx = a[l];
            st[p].bestD = 0;
            st[p].num = 0;
            st[p].den = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }

    Node query(int L, int R) { return query(1,0,n-1,L,R); }

    Node query(int p, int l, int r, int L, int R) {
        if (R < l || r < L) return Node(); // identity
        if (L <= l && r <= R) return st[p];
        int m = (l + r) >> 1;
        Node left = query(p<<1, l, m, L, R);
        Node right = query(p<<1|1, m+1, r, L, R);
        return merge(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    SegTree seg(P);

    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        // problem statement seems 1-indexed; convert to 0-indexed
        int L = a - 1, R = b - 1;
        Node ans = seg.query(L, R);

        // Reduce fraction ans.num / ans.den to R/S for output
        long long num = ans.num, den = ans.den;
        if (num == 0) {
            // 0% -> print 0/1 to keep gcd=1 and non-negative
            den = 1;
        } else {
            long long g = std::gcd(num, den);
            num /= g; den /= g;
        }

        cout << ans.bestD << ' ' << num << ' ' << den << '\n';
    }
    return 0;
}
