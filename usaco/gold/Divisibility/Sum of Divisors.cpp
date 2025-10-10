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
	const int mod = 1e9 + 7;
	const int twomodinv = 500000004;
 
	auto S = [] (ll ini, ll fim) -> ll {
		return ((((fim - ini + 1) % mod) * ((ini + fim) % mod) % mod) * twomodinv % mod);
	};
 
	ll n; cin >> n;
	ll res = 0;
	for (ll i = 1, ult; i <= n; i = ult + 1) {
		ult = n / (n / i);
		res = (res + (n / i) * S(i, ult)) % mod;
	}
	cout << res << endl;
    
    return(0);
}
