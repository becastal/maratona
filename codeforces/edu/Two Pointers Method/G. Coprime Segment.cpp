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

const int MAX = 4e5+10;
const int MAX2 = 20;

namespace sparse {
	ll m[MAX2][MAX], n;
	void build(int n2, vector<ll> v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = gcd(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	ll query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return gcd(m[j][a], m[j][b-(1<<j)+1]);
	}
}

int main()
{
    _;

	int n; cin >> n;
	vector<ll> v(n);
	for (ll& i : v) cin >> i;

	sparse::build(n, v);
	auto da = [&](int x) {
	    for (int i = 0; i + x - 1 < n; i++) {
			if (sparse::query(i, i + x - 1) == 1) {
				return 1;
			}
		}
		return 0;
	};
	
	int l = 1, r = n+1;
	while (l < r) {
		int m = (l+r)/2;

		if (da(m)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	
	if (r == n+1) return cout << -1 << endl, 0;
	cout << l << endl;
    
    return(0);
}
