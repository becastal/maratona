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

const int mod = 1e9 + 7;

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		ll n, k, res = 1; cin >> n >> k;
		for (ll i = 0; i < k; i++)	
			res = (res * n) % mod;
		cout << res << endl;
	}
    
    return(0);
}
