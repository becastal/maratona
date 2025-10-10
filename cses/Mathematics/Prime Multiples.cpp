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
 
	ll n; cin >> n;
	int k; cin >> k;
	vector<ll> v(k);
	for (ll& i : v) cin >> i;
 
	ll res = 0;
	for (int i = 1; i < (1 << k); i++) {
		__int128 agr = 1;	
		int ok = 1;
		for (int j = 0; j < k and ok; j++) {
			if (i & (1 << j)) {
				agr *= v[j];
			}
			if (agr > n) ok = 0;
		}
 
		res += ok * (__builtin_popcount(i) & 1 ? 1LL : -1LL) * (n / agr);
	}
	cout << res << endl;
    
    return 0;
}
