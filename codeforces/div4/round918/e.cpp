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
		vector<ll> v(n);
		for (ll& vi : v)
			cin >> vi;

		for (int i = 1; i < n; i += 2)
			v[i] = -v[i];

		vector<ll> pre(n, 0);
		pre[0] = v[0];
		for (int i = 1; i < n; i++)
			pre[i] = pre[i - 1] + v[i];

		bool res = false;
		set<ll> s;
		for (ll i : pre)
		{
			res |= s.count(i) or !i;
			if (res) break;
			s.insert(i);
		}

		cout << (res ? "YES" : "NO") << endl;
	}
    
    return(0);
}
