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
	int n; cin >> n;
	vector<ll> v(n);
	multiset<pair<int, int>> M;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		M.emplace(v[i], i+1);
	}
	if (is_sorted(v.begin(), v.end())) return cout << 0 << endl, 0;

	vector<pair<int, int>> res;
	if (abs(M.begin()->f) > M.rbegin()->f) {
		for (int i = 0; i < 5; i++) {
			res.emplace_back(M.begin()->s, M.begin()->s);
		}
		res.emplace_back(1, M.begin()->s);
		res.emplace_back(1, 1);

		for (int i = n; i >= 2; i--) {
			res.emplace_back(i, 1);
			res.emplace_back(1, 1);
		}

	} else {
		for (int i = 0; i < 5; i++) {
			res.emplace_back(M.rbegin()->s, M.rbegin()->s);
		}
		res.emplace_back(n, M.rbegin()->s);
		res.emplace_back(n, n);

		for (int i = 1; i <= n-1; i++) {
			res.emplace_back(i, n);
			res.emplace_back(n, n);
		}
	}

	cout << res.size() << endl;
	for (auto [i, j] : res) {
		cout << i << ' ' << j << endl;
	}
	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
