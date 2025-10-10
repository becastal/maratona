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

void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n);

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		for (int j = 31; j >= 0; j--) {
			if (x & (1 << j)) v[i].push_back(j);
		}
	}
	
	auto comp = [](vector<int>& a, vector<int>& b) {
		int n = max(a.size(), b.size());

		for (int i = 0; i < n; i++) {
			int ai = (i < a.size() ? a[i] : -1);
			int bi = (i < b.size() ? b[i] : -1);
			if (ai != bi) return ai > bi;
		}
		return true;
	};

	auto da = [&](int ii, int m) {
		auto vi = v[ii];
		for (int& j : vi) j += m;
		return comp(vi, v[ii-1]);
	};

	ll res = 0;
	for (int i = 1; i < n; i++) {
		int l = 0, r = (int)1e9;

		while (l < r) {
			int m = l + r >> 1;

			if (da(i, m)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		for (int& j : v[i]) j += l;
		res += l;
	}
	cout << res << endl;
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
