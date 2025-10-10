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

int solve() {
	int n; cin >> n;
	vector<int> v(n);
	vector<pair<int, int>> resa, resb, res;
	multiset<pair<int, int>> M;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		M.emplace(v[i], i+1);
	}
	if (is_sorted(v.begin(), v.end())) return cout << 0 << endl, 0;

	int a = M.rbegin()->f, pos = M.rbegin()->s;
	while (a < abs(M.begin()->f)) {
		resa.emplace_back(pos, pos);	
		a += a;
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] < 0) resa.emplace_back(i, pos);
	}
	for (int i = 2; i <= n; i++) {
		resa.emplace_back(i, i-1);
	}

	int a_ = M.begin()->f, pos_ = M.begin()->s;
	while (abs(a_) < abs(M.rbegin()->f)) {
		resb.emplace_back(pos_, pos_);	
		a_ += a_;
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] > 0) resb.emplace_back(i, pos_);
	}
	for (int i = 2; i <= n; i++) {
		resb.emplace_back(i, i-1);
	}

	res = (resa.size() < resb.size() ? resa : resb);
	assert(res.size() <= 31);
	cout << res.size() << endl;
	for (auto [i, j] : res) {
		cout << i << ' ' << j << endl;
	}
	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
