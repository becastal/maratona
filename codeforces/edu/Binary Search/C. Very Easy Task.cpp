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

	int n, x, y; cin >> n >> x >> y;
	ll l = 0, r = (ll)1e12 + 10;

	auto qts = [&](ll t) {
		if (t < min(x, y)) return (ll) 0;

		t -= min(x, y);
		return (ll) 1 + t / x + t / y;
	};

	while (l < r) {
		ll m = (l+r)/2;
		if (qts(m) < n) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	cout << l << endl;
    
    return(0);
}
