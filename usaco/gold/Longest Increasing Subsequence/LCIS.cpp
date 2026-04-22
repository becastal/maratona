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
	vector<vector<T>> Y;
	vector<vector<array<int, 2>>> t;

	int ub(vector<T>& v, T x) {
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	bit2d(vector<array<T, 2>> v) {
		for (auto [x, y] : v) X.push_back(x);
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());

		t.resize(X.size() + 1);
		Y.resize(t.size());
		sort(v.begin(), v.end(), [](auto a, auto b) {
			return a[1] < b[1]; });
		for (auto [x, y] : v) for (int i = ub(X, x); i < t.size(); i += i&-i)
			if (!Y[i].size() or Y[i].back() != y) Y[i].push_back(y);

		for (int i = 0; i < t.size(); i++) {
			t[i].resize(Y[i].size() + 1, {0, -1});
		}
	}

	void update(T x, T y, array<int, 2> v) {
		for (int i = ub(X, x); i < t.size(); i += i&-i) {
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) {
				t[i][j] = max(t[i][j], v);
			}
		}
	}

	array<int, 2> query(T x, T y) {
		if (x < 0 or y < 0) return {0, -1};
		array<int, 2> ans = {0, -1};
		for (int i = ub(X, x); i; i -= i&-i) {
			for (int j = ub(Y[i], y); j; j -= j&-j) {
				ans = max(ans, t[i][j]);
			}
		}
		return ans;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	int m; cin >> m;
	vector<int> B(m);
	for (int& i : B) {
		cin >> i;
	}

	vector<int> B_(B);
	sort(all(B_));
	B_.erase(unique(all(B_)), B_.end());
	for (int& i : B) {
		i = lower_bound(all(B_), i) - B_.begin();
	}

	vector<array<int, 2>> P;
	for (int j = 0; j < m; j++) {
		P.push_back({B[j], j});
	}

	bit2d bit(P);

	vector<int> Pai, Val;
	array<int, 2> res = {0, -1};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (A[i] == B_[B[j]]) {
			auto ult = bit.query(B[j] - 1, j - 1);
			int id = Pai.size();

			Pai.push_back(ult[1]);
			Val.push_back(A[i]);

			array<int, 2> cur = {ult[0] + 1, id};
			bit.update(B[j], j, cur);
			res = max(res, cur);
		}
	}

	int tam = res[0];
	cout << tam << endl;

	vector<int> Ret;
	for (int id = res[1]; id != -1; id = Pai[id]) {
		Ret.push_back(Val[id]);
	}
	reverse(all(Ret));

	for (int i : Ret) {
		cout << i << ' ';
	}
	cout << endl;

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
