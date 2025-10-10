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
	int n, m; cin >> n >> m;
	vector<vector<int>> a((1 << n), vector<int>(1 << n));
	for (int i = 0; i < (1 << n); i++) {
		a[i][i] = 1;
	}

	vector<tuple<int, int, int>> q;

	while (m--) {
		int tp; cin >> tp;
		int c1, c2, t; 

		if (tp == 1) {
			cin >> c1 >> t; c2 = c1;
		} else {
			cin >> c1 >> c2 >> t;
		}
		q.emplace_back(c1, c2, t);
	}

	reverse(q.begin(), q.end());
	for (auto [c1, c2, t] : q) {
		for (int i = 0; i < (1 << n); i++) {
			if ((i & (1 << c1)) and (i & (1 << c2)) and !(i & (1 << t))) {
				swap(a[i], a[i ^ (1 << t)]);
			}
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			cout << a[i][j];
		}
		cout << endl;
	}

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
