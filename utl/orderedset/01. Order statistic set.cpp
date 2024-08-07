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

int main()
{
    _;

	int q; cin >> q;
	ordered_set s;

	while (q--) {
		char qi; cin >> qi;
		int x; cin >> x;

		if (qi == 'I') {
			s.insert(x);
		} else if (qi == 'D') {
			s.erase(x);
		} else if (qi == 'K') {
			if (x <= 0 or x > (int)s.size()) {
				cout << "invalid" << endl;
			} else {
				cout << *s.find_by_order(x - 1) << endl;
			}
		} else if (qi == 'C') {
			cout << s.order_of_key(x) << endl;
		}
	}

    return 0;
}

