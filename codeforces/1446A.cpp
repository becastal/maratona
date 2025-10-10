#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	ll w; cin >> w;

	vector<pair<int, int>> W(n);
	for (int i = 0; i < n; i++) {
		cin >> W[i].f; W[i].s = i;
	}

	sort(rall(W));
	vector<int> res;
	ll w_ = 0;
	for (auto [wi, pos] : W) {
		if (w_ + wi <= w) {
			w_ += wi;
			res.push_back(pos);
		}
	}

	if (w_ < (w + 1) / 2 or w_ > w) return cout << -1 << endl, 0;
	cout << res.size() << endl;
	for (int i : res) cout << i + 1 << ' '; cout << endl;

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
