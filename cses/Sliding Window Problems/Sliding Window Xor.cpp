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
	int n, k; cin >> n >> k;
 
	int x_, a_, b_, c_; cin >> x_ >> a_ >> b_ >> c_;
	vector<ll> a(n); a[0] = x_;
	for (int i = 1; i < n; i++) {
		a[i] = ((a_ * a[i-1] % c_) + b_) % c_;
	}
 
	int s = accumulate(a.begin(), a.begin() + k, 0, [&](int i, int j) { return i ^ j; }), res = s;
	for (int i = k; i < n; i++) {
		s ^= a[i-k];
		s ^= a[i];
		res ^= s;
	}
	cout << res << endl;
 
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
