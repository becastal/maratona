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

int h, n;
vector<pair<int, int>> v;
// bin search na resposta. checar se mata ou nao e achar lower bound.
bool mata(ll x)
{
	ll dano = 0;
	for (int i = 0; i < n and dano < h; i++)
		dano += v[i].f * ((x -1) / v[i].s + 1);

	return dano >= h;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		cin >> h >> n;
		v.clear(); v.resize(n);
		for (auto& p : v)
			cin >> p.f;
		for (auto& p : v)
			cin >> p.s;
		
		ll l = 1, r = (int) 3 * 1e12 + 10;
		while (l < r)
		{
			ll m = (l + r) >> 1;
			if (mata(m))
				r = m;
			else
				l = m + 1;
		}
		cout << l << endl;
	}
    
    return(0);
}
