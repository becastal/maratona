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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<pair<int, int>> p(q);	
	vector<vector<int>> fins(n);
	for (int i = 0; i < q; i++) {
		auto& [l, r] = p[i];
		cin >> l >> r; l--, r--;
		fins[r].push_back(i);
	}

	map<int, int> ult;
	ordered_set ost;
	vector<int> res(q);
	for (int i = 0; i < n; i++) {
		if (ult.count(a[i])) {
			ost.erase(ult[a[i]]);
		}
		ost.insert(ult[a[i]] = i);

		for (int j : fins[i]) {
			auto [l, r] = p[j];
			res[j] = (int)ost.size() - ost.order_of_key(l);	
		}
	}

	for (int i : res) cout << i << endl;

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
