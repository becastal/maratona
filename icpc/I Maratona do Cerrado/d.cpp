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
	auto f = [](ll l, ll r) {
		//l--;
		return (r / 3 + r / 5 - r / 15) - (l / 3 + l / 5 - l / 15); 		
	};

	ll res = n, ult = 1;
	while (f(ult, res)) {
		ll ult_ = ult;
		ult = res;
		res += f(ult_, res);
	}

	cout << res << endl;
    
    return(0);
}
