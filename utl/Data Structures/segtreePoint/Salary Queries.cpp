#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 1e6+10;
int n, m;

//typedef pair<int, int> ii;
//typedef pair<int, ii> iii;
//namespace seg {
//	iii seg[4*MAX]; // max, min
//	vector<int> v;
//
//	iii combina(iii a, iii b) {
//		return {a.f + b.f, {max(a.s.f, b.s.f), min(a.s.s, b.s.s)}};
//	}
//	iii build(int p=1, int l=0, int r=n-1) {
//		if (l == r) return seg[p] = {1, {v[l], v[l]}};
//		int m = (l+r)/2;
//		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
//	}
//	int query(int a, int b, int p=1) {
//		if (b < seg[p].s.s or seg[p].s.f < a) return 0;
//		if (a <= seg[p].s.s and seg[p].s.f <= b) return seg[p].f;
//		return query(a, b, 2*p) + query(a, b, 2*p+1);
//	}
//	iii update(int i, int x, int p=1, int l=0, int r=n-1) {
//		if (i < l or r < i) return seg[p];
//		if (l == r) return seg[p] = {1, {x, x}};
//		int m = (l+r)/2;
//		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
//	}
//};

int main()
{
    _;

	cin >> n >> m;	
	ordered_set<pair<int, int>> sal;
	map<int, int> func;
 
	for (int i = 1; i <= n; i++)
	{
		int vi; cin >> vi;	
		func[i] = vi;
		sal.insert({vi, i});
	}
 
	for (int i = 0; i < m; i++)
	{
		char c; cin >> c;
		if (c == '!')
		{
			int k, x; cin >> k >> x;
			sal.erase({func[k], k});
			func[k] = x;
			sal.insert({func[k], k});
		}
		else
		{
			int a, b; cin >> a >> b;
			cout << (sal.order_of_key({b, INF}) - sal.order_of_key({a - 1, INF})) << endl;
		}
	}

    return(0);
}
