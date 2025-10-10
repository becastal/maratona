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
	int n, m; cin >> n >> m;

	vector<int> X(n), R(n);
	for (int& i : X) cin >> i;
	for (int& i : R) cin >> i;

	int Y = *max_element(R.begin(), R.end());

	vector<ll> res(Y+1, 0);
	for (int i = 0; i <= Y; i++) {
		vector<pair<int, int>> v;
		for (int j = 0; j < n; j++) {
			if (i > R[j]) continue;
			int dx = (int)floor(sqrt((ll)R[j] * R[j] - (ll)i * i));
			v.emplace_back(X[j] - dx, X[j] + dx);
		}
		if (v.empty()) continue;

		sort(v.begin(), v.end());

		int l = v[0].first, r = v[0].second;	
		for (int j = 1; j < v.size(); j++) {
			if (v[j].first <= r + 1) {
				r = max(r, v[j].second);
			} else {
				res[i] += (r - l + 1);
				l = v[j].first;
				r = v[j].second;
			}
		}
		res[i] += (r - l + 1);
	}

	cout << 2 * accumulate(res.begin(), res.end(), 0LL) - res[0] << endl;
	//set<pair<int, int>> s;
	//for (int i = 0; i < n; i++) {
	//	for (int y = -R[i]; y <= R[i]; y++) {
	//		int dx = (int)floor(sqrt((ll)R[i] * R[i] - (ll)y * y));
	//		for (int x = X[i] - dx; x <= X[i] + dx; x++) {
	//			s.emplace(x, y);
	//		}
	//	}
	//}
	//cout << s.size() << endl;
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
