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
	vector<ll> v(n);
	for (ll& vi : v)
		cin >> vi;

	ll res = 0, l = 0;
	set<ll> s;
	for (ll r = 0; r < n; r++)
	{
		s.insert(v[r]);
		while (l < n and *s.rbegin() - *s.begin() > k)
			s.erase(v[l++]);

		res += r - l + 1;
	}

	cout << res << endl;
    
    return(0);
}
