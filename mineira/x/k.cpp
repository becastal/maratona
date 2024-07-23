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
// era so brutar. sem sacanagem eu notei que dava. que animal.

int main()
{
    _;

	int n; cin >> n;
	vector<tuple<int, int, int>> v(n);
	for (auto& [ri, gi, bi] : v)
		cin >> ri >> gi >> bi;

	int dres = -1;
	tuple<int, int, int> res;
	for (int r = 0; r < 256; r++)
		for (int g = 0; g < 256; g++)
			for (int b = 0; b < 256; b++)
			{
				int d = 1000;
				for (auto [ri, gi, bi] : v)
				{
					int da = abs(r - ri) + abs(g - gi) + abs(b - bi);
					if (da < d) d = da;
				}

				if (d > dres)
				{
					dres = d;
					res = tie(r, g, b);
				}
			}

	auto [r, g, b] = res;
	cout << r << ' ' << g << ' ' << b << endl;
    
    return(0);
}
