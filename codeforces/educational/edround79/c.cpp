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
	int n, m; cin >> n >> m;
	vector<int> a(n), p(n), b(m), bit(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		p[a[i]] = i;
	}

	ll res = 0;
	ordered_set pos;
	for (int& i : b) {
		cin >> i; i--;

		if (pos.size() and *pos.rbegin() > p[i]) res++;
		else res += 2 * (p[i] - pos.order_of_key(p[i])) + 1;
		
		pos.insert(p[i]);
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
