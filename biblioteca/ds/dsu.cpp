/*
union find	

descricao:
	representa e mantem um conjunto. merge tem small
	to large e find tem compressao de caminho. nem
	sempre eh necessario, mas com essas duas a
	complexidade eh a melhor possivel.  tirar id[i]=
	do find nao precisar de compressao e tirar o que
	for relacionado com sz no merge se nao precisar
	de small to large.

complexidades:
	memoria: o(n);
	find: o(1/ackermann(n));
	merge: o(1/ackermann(n)) ~ 1;
*/

struct DSU {
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};
