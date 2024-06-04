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

	vector<int> v(n, 0);
	int l = 1;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		if (x < 0)
			x = abs(x), v[x] = i;
		else
			if (v[x] != 0)
			{
				while (l <= v[x])
					cout << i - l++ << ' ';
				v[x] = 0;
			}
	}
	while (l <= n) cout << n + 1 - l++ << ' ';
    
    return(0);
}
