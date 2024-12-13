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

	vector<ll> f = {0LL, 1LL};
	vector<ll> pares = {0};
	
	int i = 2;
	while (f.back() < (ll)5e16) {
		f.push_back(f[i-2] + f[i-1]);
		if (f[i]&1^1) pares.push_back(f[i]);
		i++;
	}

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		auto it = upper_bound(pares.begin(), pares.end(), n);
		cout << accumulate(pares.begin(), it, 0LL) << endl;
	}

    
    return(0);
}
