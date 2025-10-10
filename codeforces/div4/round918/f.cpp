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
typedef pair<ll, ll> ii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<ii> v(n);

		for (auto& vi : v)
			cin >> vi.f >> vi.s;

		sort(v.begin(), v.end(), [] (ii a, ii b) {return a.s < b.s;});

		ll res = 0;
		ordered_set st;
		for (ii p : v)
		{
			res += st.size() - st.order_of_key(p.f);
			st.insert(p.f);
		}
		
		cout << res << endl;
	}
    
    return(0);
}
