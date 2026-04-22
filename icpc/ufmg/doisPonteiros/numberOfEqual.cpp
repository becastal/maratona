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
	vector<ll> a(n), b(m);

	for (auto& ai : a)
		cin >> ai;

	for (auto& bi : b)
		cin >> bi;

	int c = 0, ai = 0, bi = 0;
	while (ai < n or bi < m)
	{
		if ((ai < n and bi < m) and a[ai] == b[bi])
		{
			int r = bi;
			while (r < m and a[ai] == b[r])
				c++, r++;
			ai++;
		}
		else if ((ai < n and a[ai] < b[bi]) or bi >= m)
			ai++;
		else if ((bi < m and b[bi] < a[ai]) or ai >= n) 
			bi++;
	}

	cout << c << endl;
    
    return(0);
}
