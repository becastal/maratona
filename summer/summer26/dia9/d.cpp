#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> movss = {
	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0}
};

signed solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	int som = 0, p = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (A[i][j] == '#') {
			som++;
			p = i * m + j;
		}
	}
	if (som <= 2) return cout << -1 << endl, 0;

	auto movs = [&](int i) {
		int a = i / m, b = i % m;
		vector<int> R;
		for (auto [di, dj] : movss) {
			int a_ = a + di, b_ = b + dj;
			if (a_ >= 0 and b_ >= 0 and a_ < n and b_ < m and A[a_][b_] == '#') {
				R.push_back(a_ * m + b_);	
			}
		}
		return R;
	};

	int N = n * m, t = 0;
	stack<int> s;
	vector<int> id(N, -1), art(N, 0);
	function<int(int, int&, int)> dfs = [&](int i, int& t, int p) {
		int lo = id[i] = t++;	
		s.push(i);

		for (auto j : movs(i)) if (j != p) {
			if (id[j] == -1) {
				int val = dfs(j, t, i);
				lo = min(lo, val);
				if (val >= id[i]) {
					art[i]++;
					while (s.top() != j) s.pop();
					s.pop();
				}
			} else lo = min(lo, id[j]);
		}
		if (p == -1 and art[i]) art[i]--;
		return lo;
	};
	dfs(p, t, -1);

	if (count(all(art), 0) != N) return cout << 1 << endl, 0;
	cout << 2 << endl;

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
