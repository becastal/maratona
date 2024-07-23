// merge sort estatica
// 
// cada nodo guarda um vetor ordenado de todos os valores do range que ele resume.
// como nao precisa atualizar, da pra ser um vetor.
// 
// build: o(nlogn)
// query: o(log logn), segundo log por causa do bin search.

namespace seg {
    vector<vector<int>> seg;
	vector<int> v;
    int n;

    void build(int p=1, int l=0, int r=n-1) {
        if (l == r)
		{
            seg[p].push_back(v[l]);
            return;
        }
        int m = (l+r)/2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        merge(seg[2*p].begin(), seg[2*p].end(), seg[2*p+1].begin(), seg[2*p+1].end(), back_inserter(seg[p]));
    }
    void build(int n2, vector<int>& v2) {
        n = n2, v = v2;
        seg.resize(4*n);
        build();
    }
    int query(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return seg[p].end() - upper_bound(seg[p].begin(), seg[p].end(), x);
        int m = (l+r)/2;
        return query(a, b, x, 2*p, l, m) + query(a, b, x, 2*p+1, m+1, r);
    }
};
