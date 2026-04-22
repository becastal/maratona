#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

#define int ll


int solve() {
	int n, q; cin >> n >> q;
	ordered_multiset<int> O;
	
	for (int i = 0, d; i < n; i++) {
		cin >> d;
		O.insert(pair<int, int>(i, d));
	}

	while (q--) {
		int p; cin >> p; p--;

		if (p < (int)O.size()) {
			pair<int, int> a = *O.find_by_order(p);
			O.erase(a);

			if (--a.second > 0) {
				O.insert(a);
			}
		}

		cout << (int)O.size() << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

