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
	int n, k; cin >> n >> k;
	map<int, vector<int>> M;

	for (int i = 0, x; i < n; i++) {
		cin >> x;

		int c = 0;
		while (x) {
			M[x].push_back(c++);
			x /= 2;
		}
	}

	int res = INF;
	for (auto [x, v] : M) {
		if (v.size() < k) continue;

		sort(v.begin(), v.end());
		res = min(res, accumulate(v.begin(), v.begin() + k, 0));
	}
	cout << res << endl;

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
