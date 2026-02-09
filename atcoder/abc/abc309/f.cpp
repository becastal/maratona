#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

8 19 22
10 12 24 
11 15 25 

*/

// BIT 2D
//
// BIT de soma, update incrementa posicao
// Tem que construir com um vetor com todos os pontos
// que vc quer um dia atualizar (os pontos q vc vai chamar update)
//
// Complexidades:
// construir - O(n log(n))
// update e query - O(log^2(n))

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

int solve() {
	int n; cin >> n;
	vector<pair<int, int>> B;

	vector<vector<int>> A(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
		sort(all(A[i]));
		B.emplace_back(A[i][1], A[i][2]);
		B.emplace_back(A[i][1] - 1, A[i][2] - 1);
	}
	sort(all(A));

	bit2d<int> bit(B);
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		while (r < n and A[l][0] == A[r][0]) {
			r++;
		}

		for (int i = l; i < r; i++) {
			if (bit.query(A[i][1] - 1, A[i][2] - 1)) return cout << "Yes" << endl, 0;
		}
		for (int i = l; i < r; i++) {
			bit.update(A[i][1], A[i][2], +1);
		}
	}
	cout << "No" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}


