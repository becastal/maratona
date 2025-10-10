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

int main()
{
    _;

	int n; cin >> n;
	vector<int> v(n);
	map<ll, ll> dp;

	for (int& i : v) cin >> i;
	auto f = [n](vector<int> v) {
		vector<ll> res = {0};
		map<ll, ll> dp;

		ll agr = 0;
		for (int i : v) {
			map<ll, ll> dp_;
			dp_[i]++;
		
			for (auto [a, b] : dp) {
				int g_ = gcd(i, a);
				dp_[g_] += b;
			}

			for (auto [a, b] : dp_) {
				agr += a * b;
			}
			dp = move(dp_);
			res.push_back(agr);
		}

		return res;
	};

	auto pre = f(v);
	reverse(v.begin(), v.end());
	auto suf = f(v);
	reverse(suf.begin(), suf.end());

	ll res = LINF;
	for (int i = 0; i < n; i++) {
		ll l = (!i ? 0 : pre[i]);
		ll r = (i == n-1 ? 0 : suf[i+1]);
		res = min(res, l + r + (ll)(i+1) * (n-i));
	}
	cout << res << endl;
    
    return(0);
}
