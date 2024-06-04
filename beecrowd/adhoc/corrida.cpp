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
	vector<pair<int, int>> v(n, {0, 0});

	for (int i = 0; i < n; i++)
		v[i].s = i + 1;

	for (auto& i : v)
	{
		for (int j = 0; j < m; j++)
		{
			int mi; cin >> mi;
			i.f += mi;
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < 3; i++)
		cout << v[i].s << endl;

    return(0);
}
