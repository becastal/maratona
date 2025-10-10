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

	map<int, int> M = {{0, k}};
	vector<pair<int, int>> A(n);

	for (auto& [r, l] : A) cin >> l >> r;
	sort(A.begin(), A.end());

	int res = 0;
	for (auto [r, l] : A) {
		auto it = M.upper_bound(l);

		if (it == M.begin()) continue;
		it = prev(it);

		auto [t, quant] = *it;
		if (--M[t] == 0) M.erase(t);
		M[r]++;
		res++;
	}
	cout << res << endl;

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
