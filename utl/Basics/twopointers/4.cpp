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

	int n; cin >> n;
	ll s; cin >> s;

	vector<ll> v(n); 
	for (ll& vi : v)
		cin >> vi;

	ll soma = 0, res = 0;
	int l = 0;
	for (int r = 0; r < n; r++)
	{
		soma += v[r];
		while (soma > s)
			soma -= v[l++];

		res += r - l + 1;
	}

	cout << res << endl;
    
    return(0);
}
