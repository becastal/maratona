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
	int n; cin >> n;
	vector<int> A(n), res(n);
	for (int& i : A) cin >> i;

	ordered_set ost;
	for (int i = 1; i <= n; i++) {
		ost.insert(i);
	}

	for (int i = n-1; i >= 0; i--) {
		res[i] = *ost.find_by_order(i - A[i]); // quantos atras de mim sao menor que eu
		ost.erase(res[i]);
	}
	for (int i : res) cout << i << ' '; cout << endl;

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
