struct Bit {
	int n;
	vector<vector<int>> F;
	Bit(int n_) : n(n_), F(2, vector<int>(n+1)) {}

	void add(int b, int i, int x) {
		for (i++; i <= n; i+=i&-i) F[b][i] += x;
	}

	void update(int l, int r, int x) {
		add(0, l, x);
		add(0, r + 1, -x);
		add(1, l, x*l);
		add(1, r + 1, -x*(r+1));
	}

	int soma(int b, int i) {
		int res = 0;
		for (i++; i; i-=i&-i) res += F[b][i];
		return res;
	}

	int pref(int i) {
		return soma(0, i) * (i + 1) - soma(1, i);
	}

	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};
