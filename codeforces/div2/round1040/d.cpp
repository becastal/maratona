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

template<typename T> ll inv_count(vector<T> l, vector<T> r = {}) {
	if (!r.size()) {
		r = l;
		sort(r.begin(), r.end());
	}
	int n = l.size();
	vector<int> v(n), bit(n);
	vector<pair<T, int>> w;
	for (int i = 0; i < n; i++) w.push_back({r[i], i+1});
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(w.begin(), w.end(), make_pair(l[i], 0));
		if (it == w.end() or it->first != l[i]) return -1; // nao da
		v[i] = it->second;
		it->second = -1;
	}

	ll ans = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = v[i]-1; j; j -= j&-j) ans += bit[j];
		for (int j = v[i]; j < n; j += j&-j) bit[j]++;
	}
	return ans;
}

int solve() {
	int n; cin >> n;
	vector<int> P(n);
	for (int& i : P) cin >> i;

	auto inv_count = [&]() {
		int m = 2*n+10;
		vector<int> F(m+1, 0);

		ll res = 0;
		for (int i = n-1; i >= 0; i--) {
			for (int j = P[i]-1; j; j-=j&-j) res += F[j];
			for (int j = P[i]; j < m; j+=j&-j) F[j]++;
		}
		return res;
	};

	ll res = inv_count();
	for (int i = 0; i < n; i++) {
		P[i] = 2*n - P[i];

		ll agr = inv_count();
		if (res > agr) {
			res = agr;
		} else {
			P[i] = 2*n - P[i];
		}
	}
	cout << res << endl;

//	vector<vector<int>> dp(n, vector<int>(2, INF));
//	dp[n-1][0] = dp[n-1][1] = 0;
//
//	for (int i = n-1; i >= 0; i--) {
//		for (int ii : {0, 1}) {
//			dp[i][ii] = 0;
//
//			int vali = (!ii ? P[i] : -P[i]);
//			for (int j = i + 1; j < n; j++) {
//				int agr = INF;
//				for (int jj : {0, 1}) {
//					int valj = (!jj ? P[j] : -P[j]);
//					agr = min(agr, dp[j][jj] + (vali > valj));
//				}
//				dp[i][ii] += agr;
//			}
//		}
//	}
//	cout << min(dp[0][0], dp[0][1]) << endl;

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
