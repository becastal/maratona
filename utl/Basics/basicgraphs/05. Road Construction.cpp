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

	int n, m; cin >> n >> m;
	vector<int> lig(n + 1, 0);
	while (m--)
	{
		int ai, bi; cin >> ai >> bi;
		lig[ai]++, lig[bi]++;
	}

	int base;
	for (int i = 1; i <= n; i++)
		if (!lig[i])
			base = i;

	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++)
		if (i != base)
			v.emplace_back(base, i);

	cout << v.size() << endl;
	for (auto [i, j] : v)
		cout << i << ' ' << j << endl;
    
    return(0);
}
