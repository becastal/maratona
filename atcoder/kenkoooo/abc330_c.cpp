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

	ll d, res = LINF; cin >> d;
	for (ll i = 0; i * i <= d; i++) {
		res = min({res,
			i*i - d,
			i*i - d + (ll)round(sqrt(abs(i*i - d))), 
			i*i - d + (ll)round(sqrt(abs(i*i - d))+1)}); 
	}
	cout << res << endl;
    
    return(0);
}
