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
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	int n; cin >> n;
	vector<int> v(n), bom(n, 0);
	for(int& i : v) cin >> i;
	ordered_set M;

	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < i + 1) {
			res += M.order_of_key(v[i] - 1);	
			M.insert(i);
		}
	}

	cout << res << endl;
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
