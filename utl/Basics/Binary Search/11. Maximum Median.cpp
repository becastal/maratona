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

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
	
	auto da = [&](ll mi) {
		ll res = 0;
		for (int i = n/2; i < n; i++) {
			if (v[i] >= mi) break;

			res += mi - v[i];
		}
		return res;
	};

	ll l = v[n/2], r = (ll)1e13;
	while (l < r) {
		ll m = (l+r)/2;
		//cout << m << ' ' << da(m) << endl;

		if (da(m) <= k) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	cout << l-1 << endl;
    
    return(0);
}
