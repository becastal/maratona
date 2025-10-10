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

	int n; cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].f; a[i] = v[i].f;
		v[i].f = v[i].f, v[i].s = -i;	
	}
	sort(v.rbegin(), v.rend());

	int q; cin >> q;
	vector<vector<pair<int, int>>> Q(q);
	vector<int> res(q);

	for (int i = 0, r, pos; i < q; i++) {
		cin >> r >> pos;
		Q[--r].emplace_back(--pos, i);
	}

	ordered_set S;
	for (int k = 0; k < n; k++) {
		S.insert(-v[k].s);

		for (auto [i, idx] : Q[k]) {
			res[idx] = a[*S.find_by_order(i)];
		}
	}

	for (int i : res) cout << i << endl;

    return(0);
}
