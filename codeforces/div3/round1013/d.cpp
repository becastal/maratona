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
	ll n, m, k;
	cin >> n >> m >> k;

	auto da = [&](ll b) {
		//if (b == 1) return (b + 1 >> 1) >= k;	
		return (n * ((m / (b+1) * (b)) + m % (b+1))) >= k;
	};

	ll l = 1, r = m;
	while (l < r) {
		ll mi = l + r >> 1;

		if (da(mi)) {
			r = mi;
		} else {
			l = mi+1;
		}
	}

	cout << l << endl;
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
