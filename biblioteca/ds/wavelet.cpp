/*
wavelet tree estatica

descricao:
	uma segtree mas encima de valores e nao de indices.

complexidades (d = maxn - minn):
	memoria: o(nlog(d));
	build: o(nlog(d));
	conta: o(log(d)),
		conta quantos em [x, y] que ocorrem em [i, j);

	soma:  o(log(d)),
		soma os em [x, y] que ocorrem em [i, j);

	somak: o(log(d)),
		soma os primeiros que ocorrem em [i, j) ordenado;

	kth:   o(log(d)),
		k-esimo menor valor que ocorre em [i, j) ordenado;

	swp:   o(log(d)),
		inverte o valor n indice i com o i+1;
*/
namespace wave {
    int n, v[MAX], delta = maxn-minn;
    vector<int> esq[4*delta], pre[4*delta];
    
    void build(int b=0, int e=n, int p=1, int l=minn, int r=maxn) {
        if (l == r) return; 
        int m=(l+r)/2; esq[p].push_back(0), pre[p].push_back(0);
        for (int i = b; i < e; i++) {
            esq[p].push_back(esq[p].back() + (v[i] <= m));
            pre[p].push_back(pre[p].back() + v[i]);
        }
        int mid = stable_partition(v + b, v + e, [m](int x) { return x <= m; })-v;
        build(b, mid, 2*p, l, m), build(mid, e, 2*p+1, m+1, r);
    }

    int conta(int i, int j, int x, int y, int p=1, int l=minn, int r=maxn) {
        if (y < l or x > r) return 0;
        if (x <= l and r <= y) return j-i;
        int m=(l+r)/2, ei = esq[p][i], ej = esq[p][j];
        return conta(ei, ej, x, y, 2*p, l, m) + conta(i-ei, j-ej, x, y, 2*p+1, m+1, r);
    }

    int soma(int i, int j, int x, int y, int p=1, int l=minn, int r=maxn) {
        if (y < l or x > r) return 0;
        if (x <= l and r <= y) return pre[p][j]-pre[p][i];
        int m=(l+r)/2, ei = esq[p][i], ej = esq[p][j];
        return soma(ei, ej, x, y, 2*p, l, m) + soma(i-ei, j-ej, x, y, 2*p+1, m+1, r);
    }

    int somak(int i, int j, int k, int p=1, int l=minn, int r=maxn) {
        if (l == r) return k*l;
        int m=(l+r)/2, ei = esq[p][i], ej = esq[p][j];
        if (k <= ej-ei) return somak(ei, ej, k, 2*p, l, m);
        return pre[2*p][ej] - pre[2*p][ei] + somak(i-ei, j-ej, k-(ej-ei), 2*p+1, m+1, r);
    }

    int kth(int i, int j, int k, int p=1, int l=minn, int r=maxn) {
        if (l == r) return l;
        int m=(l+r)/2, ei = esq[p][i], ej = esq[p][j];
        if (k <= ej-ei) return kth(ei, ej, k, 2*p, l, m);
        return kth(i-ei, j-ej, k-(ej-ei), 2*p+1, m+1, r);
    }

	void swp(int i, int p=1, int l=minn, int r=maxn) {
		if (l == r) return;
		int m=(l+r)/2;
		bool b1 = v[i]<=m, b2 = v[i+1]<=m;
		if (b1 != b2) {
			esq[p][i+1] = esq[p][i];
			esq[p][i] += (b1 ? -1 : 1);
			esq[p][i+1] += (b1 ? 1 : -1);
		}
		pre[p][i+1] = pre[p][i];
		swap(v[i], v[i+1]);
		if (b1) swp(i, 2*p, l, m);
		else swp(i, 2*p+1, m+1, r);
		
	}
}
