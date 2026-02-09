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
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) t[i][j] += v;
	}

	T query(T x, T y) {
		T ans = 0;
		for (int i = ub(X, x); i; i -= i&-i)
			for (int j = ub(Y[i], y); j; j -= j&-j) ans += t[i][j];
		return ans;
	}
	T query(T x1, T y1, T x2, T y2) {
		return query(x2, y2)-query(x2, y1-1)-query(x1-1, y2)+query(x1-1, y1-1);
	}
};

vector<int> pi(string& s) {
	int n = (int)s.size();
	vector<int> r(n);
	for (int i = 1, j = 0; i < n; i++) { 
		while (j and s[i] != s[j]) j = r[j-1];
		r[i] = (j += s[i] == s[j]);
	}
	return r;
}

void euler(vector<vector<int>>& G, vector<int>& L, vector<int>& R) {
	int n = (int)G.size(), t = 0;
	L = vector<int>(n, -1);
	R = vector<int>(n, -1);

	function<void(int, int)> dfs = [&](int u, int p){ 
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			dfs(v, u);
		}
		R[u] = t;
	};
	dfs(0, -1);
}

int solve() {
	int n, q; cin >> n >> q;
	string S; cin >> S;

	vector<int> P = pi(S);
	reverse(all(S));
	vector<int> P_ = pi(S);

	vector<vector<int>> G(n+1), G_(n+1);
	for (int i = 1; i <= n; i++) {
		G[P[i-1]].push_back(i);
		G_[P_[i-1]].push_back(i);
	}
	
	vector<int> L, R, L_, R_;
	euler(G, L, R);
	euler(G_, L_, R_);

	vector<pair<int, int>> Pt;
	for (int i = 0; i <= n; i++) {
		Pt.emplace_back(L[i], L_[n-i]);
	}
	sort(all(Pt));
	bit2d<int> bit(Pt);

	for (auto [a, b] : Pt) {
		bit.update(a, b, +1);
	}

	while (q--) {
		int x, y; cin >> x >> y;

		int x1 = L[x], x2 = R[x] - 1;
		int y1 = L_[y], y2 = R_[y] - 1;
		cout << bit.query(x1, y1, x2, y2) << endl;
	}

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

