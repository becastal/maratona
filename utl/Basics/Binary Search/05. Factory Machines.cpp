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
 
	ll n, t; cin >> n >> t;
	vector<ll> v(n);
	for (ll& vi : v)
		cin >> vi;
 
	function<bool(ll)> da = [&] (ll ti) {
		ll quant = 0;	
		for (ll vi : v)
		{
			quant += ti / vi;
			if (quant >= t) break;
		}
		return quant >= t;
	};
 
	ll l = 0, r = (ll)1e18;
	while (l < r)
	{
		ll m = (r + l) >> 1;
		if (da(m))
			r = m;
		else
			l = m + 1;
	}
 
	cout << l << endl;
    
    return(0);
}
