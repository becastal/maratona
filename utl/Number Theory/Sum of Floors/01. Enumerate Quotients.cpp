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
	vector<ll> res;
	for (ll i = 1, ult; i <= n; i = ult + 1) {
		ult = n / (n / i);
		res.push_back(n / i);
	}
	reverse(res.begin(), res.end());
	for (ll i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
