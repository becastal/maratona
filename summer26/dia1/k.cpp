#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n;
	vector<int> id, sz;

	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int a) {
		return a == id[a] ? a : find(id[a]);
	}

	int merge(int a, int b) {
		if ((a = find(a)) == (b = find(b))) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		//sz[a] += sz[b];
		id[b] = a;
		return 1;
	}
};

signed solve() {
	int n; cin >> n;
	vector<int> A(n), D(n);

	for (int& i : A) {
		cin >> i;
	}
	for (int& i : D) {
		cin >> i;
	}

	vector<int> B(n);
	iota(all(B), 0);

	set<int> V;
	for (int i = 0; i < n; i++) {
		V.insert(i);
	}

	for (int i = 0; i < n; i++) {
		int res = 0;
		vector<int> B_;
		set<int> M_;

		for (int j : B) if (V.count(j)) {
			int dano = 0;
			auto it = V.find(j);

			if (it != V.begin()) {
				dano += A[*prev(it)];
			}
			if (next(it) != V.end()) {
				dano += A[*next(it)];
			}

			if (dano > D[j]) {
				res++;
				M_.insert(j);

				if (it != V.begin()) {
					B_.push_back(*prev(it));
				}
				if (next(it) != V.end()) {
					B_.push_back(*next(it));
				}
			}
		}

		for (int j : M_) {
			V.erase(j);
		}
		sort(all(B_));
		B_.erase(unique(all(B_)), B_.end());

		B = move(B_);
		cout << res << " \n"[i==n-1];
	}

//	Dsu dsu(n);
//	for (int i = 0; i < n; i++) {
//		vector<int> B_;
//		int res = 0;
//
//		for (int j : B) {
//			int dano = 0;
//			if (j) dano += A[dsu.find(j-1)];
//			if (j + 1 < n) dano += A[dsu.find(j+1)];
//			if (dano > D[j]) {
//				res++;
//				if (j + 1 < n) {
//					dsu.merge(j, dsu.find(j+1));
//				} else {
//					dsu.merge(j, dsu.find(j-1));
//				}
//				if (j) B_.push_back(dsu.find(j-1));
//				if (j + 1 < n) B_.push_back(dsu.find(j+1));
//			}
//		}
//		B = move(B_);
//		cout << res << " \n"[i==n-1];
//	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
