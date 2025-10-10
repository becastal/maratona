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
using ordered_multiset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> a(n), b(n);

	ordered_multiset s;
	for (int i = 0; i < n; i++) {
		s.insert({v[i], i});
		a[i] = s.find_by_order(((int)s.size()-1)/2)->f;
	}
	auto a_ = a;
	for (int i = 1; i < n; i++) {
		a[i] = min(a[i], a[i-1]);
		a_[i] = max(a_[i], a_[i-1]);
	}

	s.clear();
	for (int i = n-1; i >= 0; i--) {
		s.insert({v[i], i});
		b[i] = s.find_by_order(((int)s.size()-1)/2)->f;
	}
	auto b_ = b;
	for (int i = n-2; i >= 0; i--) {
		b[i] = min(b[i], b[i+1]);
		b_[i] = max(b_[i], b_[i+1]);
	}

	int ok = 0;
	for (int i = 1; i < n-1 and !ok; i++) {
		ok |= max(a[i-1], b[i+1]) <= k;
		//ok |= min(a_[i-1], b_[i+1]) <= k;
	}
	cout << (ok ? "YES" : "NO") << endl;

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
