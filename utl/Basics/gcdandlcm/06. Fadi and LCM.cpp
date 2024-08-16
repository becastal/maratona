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

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main()
{
    _;

	ll n; cin >> n;

	ll res;
	for (ll i = 1; i * i <= n; i++)
		if (!(n % i) and lcm(i, n / i) == n)
			res = i;
	
	cout << res << ' ' << n / res << endl;
    
    return(0);
}

