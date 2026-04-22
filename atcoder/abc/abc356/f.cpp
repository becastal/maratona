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
	vector<int> p, sz;
	stack<int> S;

	Dsu(int n_) : n(n_), p(n), sz(n, 1) {
		iota(all(p), 0);
	}
	int find(int a) {
		while (p[a] != a) a = p[a];
		return a;
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return S.push(-1);
		if (sz[a] > sz[b]) swap(a, b);
		S.push(a);
		sz[b] += sz[a];
		p[a] = b;
	}
	int query(int a) {
		return sz[find(a)];
	}
	void rollback() {
		int u = S.top(); S.pop();
		if (u == -1) return;
		sz[p[u]] -= sz[u];
		p[u] = u;
	}
};

int solve() {
	int n, k; cin >> n >> k;

	vector<array<int, 2>> Q(n);
	vector<int> Comp(n);

	for (int i = 0; i < n; i++) {
		auto& [tp, x] = Q[i];
		cin >> tp >> x;
		Comp[i] = x;
	}

	sort(all(Comp));
	Comp.erase(unique(all(Comp)), Comp.end());
	auto id = [&](int x) {
		return lower_bound(all(Comp), x) - Comp.begin();
	};

	set<int> S;
	vector<array<int, 3>> A;
	vector<int> Ponta;
	map<array<int, 2>, int> L;
	int t = 0;

	auto add_edge = [&](int a, int b) {
		if (a > b) swap(a, b);

		array<int, 2> edge{a, b};
		A.push_back({1, a, b});
		Ponta.push_back(0);
		L[edge] = t++;
	};
	auto rem_edge = [&](int a, int b) { 
		if (a > b) swap(a, b);

		array<int, 2> edge{a, b};
		if (!L.count(edge)) return;
		A.push_back({2, a, b});
		Ponta.push_back(0);
		Ponta[L[edge]] = t;
		Ponta[t++] = L[edge];
		L.erase(edge);
	};
	auto add_query = [&](int a) {
		A.push_back({3, a, -1});	
		Ponta.push_back(-1);
		t++;
	};

	for (auto [tp, x] : Q) {
		int eu = id(x);

		if (tp == 1) {
			if (S.count(x)) {
				auto it = S.find(x);

				if (it != S.begin() and next(it) != S.end() and abs(*prev(it) - *next(it)) <= k) {
					int a = id(*prev(it));
					int b = id(*next(it));
					add_edge(a, b);
				}

				if (it != S.begin() and abs(*prev(it) - x) <= k) {
					int a = id(*prev(it));
					rem_edge(a, eu);
				}

				if (next(it) != S.end() and abs(*next(it) - x) <= k) {
					int a = id(*next(it));
					rem_edge(a, eu);
				}

				S.erase(x);
			} else {
				auto it = S.insert(x).first;

				if (it != S.begin() and next(it) != S.end()) {
					int a = id(*prev(it));
					int b = id(*next(it));
					rem_edge(a, b);
				}

				if (it != S.begin() and abs(*prev(it) - x) <= k) {
					int a = id(*prev(it));
					add_edge(a, eu);
				}

				if (next(it) != S.end() and abs(*next(it) - x) <= k) {
					int a = id(*next(it));
					add_edge(a, eu);
				}
			}
		} else {
			add_query(eu);
		}

		//puts("~~~~~~~~~~~~~~~~~~");
		//for (int j = 0; j < t; j++) {
		//	auto [tp_, a, b] = A[j];
		//	printf("A[%lld] = {%lld, %lld, %lld}, Ponta[%lld] = %lld\n", j, tp_, a, b, j, Ponta[j]);
		//}
	}
	for (auto [edge, pos] : L) {
		Ponta[pos] = t;
	}
	//puts("!!!!!!!!!!!!!!!");
	//for (int j = 0; j < t; j++) {
	//	auto [tp_, a, b] = A[j];
	//	printf("A[%lld] = {%lld, %lld, %lld}, Ponta[%lld] = %lld\n", j, tp_, a, b, j, Ponta[j]);
	//}

	Dsu dsu(t);
	vector<int> Res(t, -1);
	function<void(int, int)> calc = [&](int l, int r) {
		if (l >= r) {
			if (A[l][0] == 3) {
				Res[l] = dsu.query(A[l][1]);	
			}
			return;
		}

		int m = (l + r) / 2, cont = 1;
		for (int i = m+1; i <= r; i++) if (Ponta[i] + 1 and Ponta[i] < l) {
			auto [tp, a, b] = A[i];
			dsu.unite(a, b), cont++;
		}
		calc(l, m);

		while (--cont) dsu.rollback();
		for (int i = l; i <= m; i++) if (Ponta[i] + 1 and Ponta[i] > r) {
			auto [tp, a, b] = A[i];
			dsu.unite(a, b), cont++;
		}
		calc(m + 1, r);
		while (cont--) dsu.rollback();
	};
	calc(0, t - 1);

	for (int i = 0; i < t; i++) if (Res[i] != -1) {
		cout << Res[i] << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
