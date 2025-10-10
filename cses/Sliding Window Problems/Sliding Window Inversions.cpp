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


int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	ordered_multiset<int> ost;

	ll res = 0;
	auto poe = [&](int i) {
		res += (int)ost.size() - ost.order_of_key({A[i], i});
		ost.insert({A[i], i});
	};
	auto tira = [&](int i) {
		res -= ost.order_of_key({A[i], i});
		ost.erase({A[i], i});
	};

	for (int i = 0; i < k; i++) {
		poe(i);
	}

	cout << res << ' ';
	for (int i = k; i < n; i++) {
		tira(i - k);
		poe(i);
		cout << res << " \n"[i==n-1];
	}

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
