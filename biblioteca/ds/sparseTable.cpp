/*
sparse-table

descricao:
	resume intervalos com uma manha de bits
	bem parecida com a Fenwick.

complexidades:
	memoria: o(n);
	build: o(nlogn);
	query: o(1), min de [a, b];
*/

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
