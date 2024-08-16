/*
	binary indexed tree 2d (fenwick)

	descricao:
		serve pra queries associativas agora com uma dimensao a mais
		
	complexidades:
		memoria: o(n^2);
		build:  o(n^2log^2n);
		query:  o(log^2n), soma do retangulo entre p(x2, y2) e p(x1, y1);
		update: o(log^2n), soma x em i;
*/

namespace bit2d {
	vector<vector<int>> fen, v;
	int n;

	void build() {
		fen.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fen[i][j] = v[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = i | (i + 1), y = j | (j + 1);
				if (x < n) fen[x][j] += fen[i][j];
				if (y < n) fen[i][y] += fen[i][j];
				if (x < n && y < n) fen[x][y] -= fen[i][j];
			}
		}
	}

	int pre(int x, int y) {
	    int res = 0;
	    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
	        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
	            res += fen[i][j];
	        }
	    }
	    return res;
	}

	int query(int x1, int y1, int x2, int y2) {
	    return pre(x2, y2) - pre(x1 - 1, y2) - pre(x2, y1 - 1) + pre(x1 - 1, y1 - 1);
	}

	void update(int x, int y, int val) {
	    for (int i = x; i < n; i = i | (i + 1)) {
	        for (int j = y; j < n; j = j | (j + 1)) {
	            fen[i][j] += val;
	        }
	    }
	}
}

