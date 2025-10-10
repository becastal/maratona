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
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int solve() {
	int n, k, l, r; cin >> n >> k >> l >> r;

	vector<int> A(n);
	for (int& i : A) cin >> i;

	map<int, int> P;
	ordered_set ost;

	vector<ll> diff(n+10, 0);
	for (int i = 0; i < n; i++) {
		if (P.count(A[i])) {
			ost.erase(P[A[i]]);
		}
		ost.insert(P[A[i]] = i);

		if (ost.size() < k) continue;

		int pk = *ost.find_by_order((int)ost.size() - k), pk1;
		
		if ((int)ost.size() >= k + 1) {
			pk1 = *ost.find_by_order((int)ost.size() - k - 1);
		} else {
			pk1 = -1;
		}

		int f = max(1, i - pk + 1);
		int g = min(n, i - pk1);
		if (f <= g) diff[f]++, diff[g + 1]--;
	}

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i-1];
		if (i >= l and i <= r) res += diff[i];
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

