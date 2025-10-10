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
	ll n, k; cin >> n >> k;

	ll res = 0, M = 1 + n >> 1, l = 1, r = n, h = 0;
	while (r - l + 1 >= k) {
		ll m = r + l >> 1;

		if (r - l + 1 & 1) {
			res += M * (1LL << h);
		}
		r = m - (r - l + 1 & 1);
		h++;
	}
	cout << res << endl;

	//int n, k, res = 0; cin >> n >> k;
	//map<int, ll> H;
	//map<int, vector<pair<int, int>>> Hs;
	//function<void(int, int, int)> f = [&](int l, int r, int h) {
	//	if (r - l + 1 < k) return;
	//	int m = l + r >> 1;
	//	Hs[h].emplace_back(l, r);

	//	if (r - l + 1 & 1) {
	//		res += m;	
	//		H[h] += m;
	//		f(l, m - 1, h + 1);
	//		f(m + 1, r, h + 1);
	//	} else {
	//		f(l, m, h + 1);
	//		f(m + 1, r, h + 1);
	//	}
	//};
	//f(1, n, 0);

	//for (auto [hi, v] : H) {
	//	cout << hi << ": " << v << endl;
	//}
	//for (auto [hi, v] : Hs) {
	//	cout << hi << ": " << "(" << v[0].f << ", " << v[0].s << ")" << endl;
	//}

	//cout << res << endl;

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
