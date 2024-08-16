/*
	binary indexed tree (fenwick)

	descricao:
		serve pra queries associativas em range [0, r];
		
	complexidades:
		memoria: o(n);
		build:  o(n);
		query:  o(logn), soma de [l, r]
		update: o(logn), soma x em i
*/

namespace bit {
	vector<int> fen, v;
	int n;

	void build() {
		fen.assign(n, 0);
		for (int i = 0; i < n; i++) {
			fen[i] += v[i];
			int r = i | (i + 1);
			if (r < n) fen[r] += fen[i];
		}
	}

	int pre(int r) {
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += fen[r];
		return res;
	}

	int query(int l, int r) {
		return pre(r) - pre(l - 1);
	}

	void update(int i, int x) {
		for (; i < n; i = i | (i + 1))
			fen[i] += x;
	}
}

// para range update e point query:
{
	void update(int i, int x) {
		for (++i; i < n; i += i & -i) 
			fen[i] += x;
	}

	void range_update(int l, int r, int x) {
		update(l, x);
		update(r + 1, -x);
	}

	int point_query(int i) {
		int res = 0;
		for (++i; i < n; i += i & -i) 
			res += fen[i];
		return res
	}
}
