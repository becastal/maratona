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
	ll k, l1, r1, l2, r2;
	cin >> k >> l1 >> r1 >> l2 >> r2;

	vector<ll> kn = {1};
	ll agr = k;
	while (agr <= (ll)2e10 / k) {
		kn.push_back(agr);
		agr *= k;
	}
	if (find(kn.begin(), kn.end(), k) == kn.end()) kn.push_back(k);

	ll res = 0;
	for (ll ki : kn) {
		ll L = (l2 + ki - 1) / ki;
		ll R = r2 / ki;
		res += max(0LL, min(R, r1) - max(L, l1) + 1);
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
