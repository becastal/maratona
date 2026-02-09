#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<typename T>
struct swag { 
	stack<pair<T, T>> in, out;

	T e() { return LLONG_MAX; };
	T op(T a, T b) {
		return min(a, b);
	}
	void push(T x) {
		in.emplace(x, op(x, in.empty() ? e() : in.top().second));
	}
	void pop() {
		if (!out.empty()) {
			out.pop();
			return;
		}

		while (!in.empty()) {
			auto [a, b] = in.top(); in.pop();
			out.emplace(a, op(a, out.empty() ? e() : out.top().second));
		}
		out.pop();
	}
	T query() {
		return op(in.empty() ? e() : in.top().second, out.empty() ? e() : out.top().second);
	}
	int size() { return in.size() + out.size(); };
	bool empty() { return in.empty() and out.empty(); };
};

int solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<string> A(n);
	for (auto& a : A) {
		cin >> a;
	}

	vector<array<int, 2>> Q(q);
	for (auto& [a, b] : Q) {
		cin >> a >> b; a--, b--;
		A[a][b] = 'X';
	}
	reverse(all(Q));

	int res = 0;
	vector<vector<int>> Ha(n, vector<int>(m)), Hb(n, vector<int>(m)), dp(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 'X') {
				Ha[i][j] = 0;
				dp[i][j] = 0;
			} else {
				dp[i][j] = 1 + min({
					i ? dp[i-1][j] : 0,	
					j ? dp[i][j-1] : 0,
					i and j ? dp[i-1][j-1] : 0
				});
				Ha[i][j] = 1 + (i ? Ha[i-1][j] : 0);
			}
			res = max(res, dp[i][j]);
		}
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 'X') {
				Hb[i][j] = 0;
			} else {
				Hb[i][j] = 1 + (i + 1 < n ? Hb[i+1][j] : 0);
			}
		}
	}

	vector<int> Res(q);
	for (int qi = 0; qi < q; qi++) {
		auto [a, b] = Q[qi];

		Res[qi] = res;
		A[a][b] = '.';
		for (int i = 0; i < n; i++) {
			if (A[i][b] == 'X') {
				Ha[i][b] = 0;
			} else {
				Ha[i][b] = 1 + (i ? Ha[i-1][b] : 0);
			}
		}

		for (int i = n-1; i >= 0; i--) {
			if (A[i][b] == 'X') {
				Hb[i][b] = 0;
			} else {
				Hb[i][b] = 1 + (i + 1 < n ? Hb[i+1][b] : 0);
			}
		}

		auto da = [&](int tam) {
			if (tam == 1) return 1;
			
			swag<int> cima, baixo;
			for (int i = 0; i < tam; i++) {
				cima.push(Ha[a][i]);	
				baixo.push(Hb[a][i]);	
			}

			if (cima.query() + baixo.query() - 1 >= tam) return 1;
			for (int i = tam; i < m; i++) {
				cima.pop(), baixo.pop();
				cima.push(Ha[a][i]);	
				baixo.push(Hb[a][i]);	
				if (cima.query() + baixo.query() - 1 >= tam) return 1;
			}
			return 0;
		};

		int l = 1, r = m, agr = 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (da(mid)) {
				l = mid + 1;
				agr = mid;
			} else {
				r = mid - 1;
			}
		}
		res = max(res, agr);
	}

	reverse(all(Res));
	for (int i : Res) {
		cout << i << endl;
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
