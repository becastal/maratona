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
template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;


int main()
{
    _;

	ordered_multiset<int> v;
	vector<int> res;

	int n, m; cin >> n >> m;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		v.insert({x, i+1});
	}

	int sz = n;
	while (v.find_by_order((sz & 1 ? (sz + 1) / 2 : sz / 2) - 1)->f != m) {
		if (v.find_by_order((sz & 1 ? (sz + 1) / 2 : sz / 2) - 1)->f > m) {
			auto it = v.find_by_order(sz-1);	
			res.push_back(it->s);
			v.erase(it);
		} else {
			auto it = v.find_by_order(0);	
			res.push_back(it->s);
			v.erase(it);
		}
		sz--;
	};

	cout << res.size() << endl;
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
