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

vector<int> v;

void solve() {
	int k; cin >> k;

	int X = 0, Y = 0;
	vector<pair<int, int>> res;
	while (k) {
		auto it = upper_bound(v.begin(), v.end(), k);
		if (it != v.begin()) {
			it--;
		} else {
			assert(0);
		}
		int pts = it - v.begin() + 1;	

		for (int i = 0; i < pts; i++) {
			res.emplace_back(X++, Y);
		}
		Y++, X++;

		assert(k >= *it);
		k -= *it;
	}

	cout << res.size() << endl;	
	for (auto [x, y] : res) {
		cout << x << ' ' << y << endl;
	}
}

int main()
{
    _;

	for (int i = 1; i * (i - 1) / 2 < 1e6; i++) {
		v.push_back(i * (i - 1) / 2);	
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
