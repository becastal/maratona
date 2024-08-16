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

	int w, h, n; cin >> w >> h >> n;

	function<bool(ll)> cabe = [&] (ll t) {
		return (t / w) * (t / h) >= n;
	};

	ll l = 0, r = 1;

	while (!cabe(r))
		r <<= 1;

	while (l < r)
	{
		ll m = (l + r) >> 1;
		if (cabe(m))
			r = m;
		else
			l = m + 1;
	}

	cout << l << endl;
    
    return(0);
}
