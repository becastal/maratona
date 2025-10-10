#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m)), pre(n+1, vector<int>(m+1, 0));;
	for (auto& a : v) for (auto& b : a) cin >> b, b = !b;

	//o(nmlog(min(n,m)) + q)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] = v[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}

	auto query = [&](int i, int j, int ii, int jj) {
		return pre[ii][jj] - pre[ii][j-1] - pre[i-1][jj] + pre[i-1][j-1];
	};

	auto da = [&](int tam) {
		int ok = 0;
		for (int i = 0; i <= n - tam; i++) {
			for (int j = 0; j <= m - tam; j++) {
				ok |= !query(i+1, j+1, i + tam, j + tam);
			}
		}
		return ok;
	};

	vector<int> res(max(n, m)+1, 0);
	int l = 1, r = min(n, m);
	while (l < r) {
		int mi = (l+r)/2;

		if (da(mi)) {
			l = mi + 1;
		} else {
			r = mi;
		}
	}

	for (int i = 0; i < l; i++) {
		res[i] = 1;
	}

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << (res[x] ? "yes" : "no") << endl;
	}
    
    return(0);
}
