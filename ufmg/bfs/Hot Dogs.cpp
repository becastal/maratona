#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int k, n, m; cin >> k >> n >> m;

	vector D(n, vector<int>(m, INF));
	queue<array<int, 2>> Q;
	for (int i = 0, ui, uj; i < k; i++) {
		cin >> ui >> uj;
		D[ui][uj] = 0;
		Q.push({ui, uj});
	}

	vector<array<int, 2>> movs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	auto valido = [&](int i, int j) { return i >= 0 and j >= 0 and i < n and j < m; };
	while (Q.size()) {
		auto [ui, uj] = Q.front(); Q.pop();

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj) or D[vi][vj] != INF) continue;
			D[vi][vj] = D[ui][uj] + 1;
			Q.push({vi, vj});
		}
	}

	auto da = [&](int mid) {
		int min_soma = INF, max_soma = -INF, min_dif = INF, max_dif = -INF, ok = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) if (D[i][j] >= mid) {
				int soma = i + j, dif = i - j;
				min_soma = min(min_soma, soma);
				max_soma = max(max_soma, soma);
				min_dif = min(min_dif, dif);
				max_dif = max(max_dif, dif);
				ok = 1;
			}
		}

		if (!ok) return false;
		int max_manhatan = max(max_soma - min_soma, max_dif - min_dif);
		return max_manhatan >= mid;
	};

	int l = 0, r = n*m, res = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;	

		if (da(mid)) {
			l = mid+1;
			res = mid;
		} else {
			r = mid-1;
		}
	}

	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
