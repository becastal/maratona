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

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> v(n);
		for (int& vi : v)
			cin >> vi;

		ll res = 0;
		map<tuple<int, int, int>, ll> mp;
		for (int i = 0; i < n - 2; i++)
		{
			auto eu = make_tuple(v[i], v[i + 1], v[i + 1]);
			auto a = make_tuple(v[i], v[i + 1], 0);
			auto b = make_tuple(v[i], 0, v[i + 2]);
			auto c = make_tuple(0, v[i + 1], v[i + 2]);

			res += mp[a]++;
			res += mp[b]++;
			res += mp[c]++;
			
			res += 3 * mp[eu]++;
			cout << i << ' ' << res << endl;
		}

		for (auto [T, cont] : mp)
		{
			auto [a, b, c] = T;
			cout << a << ' ' << b << ' ' << c << " : " << cont << endl;
		}
		cout << res << endl;
	}
    
    return(0);
}
