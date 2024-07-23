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
	vector<ll> divs;

	for (ll i = 1; i * i <= n; i++)
		if (!(n % i))
		{
			divs.push_back(i);
			if (n / i != i) divs.push_back(n / i);
		}
	
	if (k > divs.size())
		return cout << -1 << endl, 0;

	sort(divs.begin(), divs.end());
	cout << divs[k - 1] << endl;
    
    return(0);
}
