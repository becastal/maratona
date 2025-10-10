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

	vector<pair<int, int>> a(n);
	vector<int> L, R;

	for (auto& [l, r] : a) {
		cin >> l >> r;
		L.push_back(l);
		R.push_back(r);
	}

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int res = n;
	for (auto [l, r] : a) {
		int x = lower_bound(R.begin(), R.end(), l) - R.begin();	
		x += L.end() - upper_bound(L.begin(), L.end(), r);
		res = min(res, x);
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
