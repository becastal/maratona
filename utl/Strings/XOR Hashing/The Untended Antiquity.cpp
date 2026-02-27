#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<class T = int> struct bit2d {
	vector<T> X;
	vector<vector<T>> Y, t;

	int ub(vector<T>& v, T x) {
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	bit2d(vector<pair<T, T>> v) {
		for (auto [x, y] : v) X.push_back(x);
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());

		t.resize(X.size() + 1);
		Y.resize(t.size());
		sort(v.begin(), v.end(), [](auto a, auto b) {
			return a.second < b.second; });
		for (auto [x, y] : v) for (int i = ub(X, x); i < t.size(); i += i&-i)
			if (!Y[i].size() or Y[i].back() != y) Y[i].push_back(y);

		for (int i = 0; i < t.size(); i++) t[i].resize(Y[i].size() + 1);
	}

	void update(T x, T y, T v) {
		for (int i = ub(X, x); i < t.size(); i += i&-i)
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) t[i][j] ^= v;
	}

	T query(T x, T y) {
		T ans = 0;
		for (int i = ub(X, x); i; i -= i&-i)
			for (int j = ub(Y[i], y); j; j -= j&-j) ans ^= t[i][j];
		return ans;
	}
	T query(T x1, T y1, T x2, T y2) {
		return query(x2, y2)^query(x2, y1-1)^query(x1-1, y2)^query(x1-1, y1-1);
	}
};

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve() {
	int n, m, q; cin >> n >> m >> q;

	vector<int> H(q);
	for (int i = 0; i < q; i++) {
		H[i] = uniform(1, 1000000000000000000LL);
	}

	vector<pair<int, int>> A;
	vector<array<int, 5>> Q(q);
	for (auto& [tp, x1, y1, x2, y2] : Q) {
		cin >> tp >> x1 >> y1 >> x2 >> y2;

		if (tp <= 2) {
			A.emplace_back(x1, y1);
			A.emplace_back(x1, y2 + 1);
			A.emplace_back(x2 + 1, y1);
			A.emplace_back(x2 + 1, y2 + 1);
		} else {
			A.emplace_back(x1, y1);
			A.emplace_back(x2, y2);
		}
	}

	bit2d<int> bit(A);
	map<array<int, 5>, int> M;

	for (int qi = 0; qi < q; qi++) {
		auto [tp, x1, y1, x2, y2] = Q[qi];

		if (tp == 1) {
			int x = H[qi];
			bit.update(x1, y1, x);
			bit.update(x1, y2 + 1, x);
			bit.update(x2 + 1, y1, x);
			bit.update(x2 + 1, y2 + 1, x);
			M[Q[qi]] = qi;
		} else if (tp == 2) {
			Q[qi][0]--;
			int qi_ = M[Q[qi]];
			Q[qi][1]--;

			int x = H[qi_];
			bit.update(x1, y1, x);
			bit.update(x1, y2 + 1, x);
			bit.update(x2 + 1, y1, x);
			bit.update(x2 + 1, y2 + 1, x);
		} else if (tp == 3) {
			cout << (bit.query(x1, y1) == bit.query(x2, y2) ? "Yes" : "No") << endl;	
		}
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
