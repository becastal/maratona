#include <bits/stdc++.h>
// #include "../../geodeb.h"
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int conta(vector<pair<int, int>>& ls)
{
	sort(ls.begin(), ls.end());
	int resp = 0;
	for (auto& li : ls)
	{
		if (li.s - li.f == 0) continue;

		if (li.s - li.f > 0)
			for (auto it = upper_bound(ls.begin(), ls.end(), make_pair(li.f, INF)); it != ls.end(); it++)
				if (it->s < li.s)
					resp++;
		else
			for (auto it = lower_bound(ls.begin(), ls.end(), make_pair(li.f, INF)); it != ls.begin(); it--)
				if (it->s > li.s)
					resp++;
	}

	return resp;
}

int main()
{
    _;
	// GD_INIT("geo.html");

    int x, y; cin >> x >> y;
	// GD_RECT(0, 0, x, y);

	int h, v; cin >> h >> v;
	vector<pair<int, int>> hs(h), vs(v);

	for (auto& hi : hs)
	{
		cin >> hi.f >> hi.s;
		// GD_SEGMENT(0, hi.f, x, hi.s);
	}

	for (auto& vi : vs)
	{
		cin >> vi.s >> vi.f;
		// GD_SEGMENT(vi.f, 0, vi.s, y);
	}

	int pedacos = (h + 1) * (v + 1);
	pedacos += conta(hs);
	pedacos += conta(vs);
	
	cout << pedacos << endl;
    return(0);
}
