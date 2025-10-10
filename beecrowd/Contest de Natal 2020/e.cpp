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

	ll n, k; cin >> n >> k;
	ll res = 0;
	while (n--) {
		ll x; cin >> x;
		res ^= x % k;
	}
	cout << (res ? "Dali" : "Dila") << endl;
    
    return(0);
}
