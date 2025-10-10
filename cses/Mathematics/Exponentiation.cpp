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
 
ll expo(ll a, ll b, ll m) {
	if (!b) return 1;
	ll ans = expo(a*a%m, b/2, m);
	if (b%2) ans *= a;
	return ans%m;
}
 
int main()
{
    _;
 
	int n; cin >> n;
	while (n--) {
		ll a, b; cin >> a >> b;
		cout << expo(a, b, (ll)1e9+7) << endl;
	}
 
 
    
    return(0);
}
