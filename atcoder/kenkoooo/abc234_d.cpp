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

	ordered_set S;

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	for (int i = 0; i < k; i++) {
		S.insert(v[i]);
	}

	cout << *S.find_by_order(S.size() - k) << endl;
	for (int i = k; i < n; i++) {
		S.insert(v[i]);
		cout << *S.find_by_order(S.size() - k) << endl;
	}
    
    return(0);
}
