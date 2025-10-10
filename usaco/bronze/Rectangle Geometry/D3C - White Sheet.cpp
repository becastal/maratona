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

int solve() {
	vector<pair<int, int>> v(6);

	for (auto& [x, y] : v) cin >> x >> y;
	auto v_ = v;

	map<int, int> X, Y;
	sort(v_.begin(), v_.end());
	int ii = 1;
	for (auto [x, y] : v_) X[x] = ii++;

	sort(v_.begin(), v_.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.s < b.s;
	});
	ii = 1;
	for (auto [x, y] : v_) Y[y] = ii++;
	for (auto& [x, y] : v) x = X[x], y = Y[y];


	vector<vector<int>> M(10, vector<int>(10, 0));
	for (int i = v[2].f; i < v[3].f; i++) {
		for (int j = v[2].s; j < v[3].s; j++) {
			M[i][j] = 1;	
		}
	}
	for (int i = v[4].f; i < v[5].f; i++) {
		for (int j = v[4].s; j < v[5].s; j++) {
			M[i][j] = 1;
		}
	}

	int res = 0;
	for (int i = v[0].f; i < v[1].f; i++) {
		for (int j = v[0].s; j < v[1].s; j++) {
			res |= !(M[i][j]);
		}
	}
	cout << (res ? "YES" : "NO") << endl;

	return(0);
}

int main()
{
    _;

	int t = 1;// cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
