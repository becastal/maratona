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

	int n, k; cin >> n >> k;
	
	vector<int> v(n);
	for (auto& vi : v)
		cin >> vi;

	vector<int> f(1e5 + 10, 0);
	int l = 0, u = 0, c = 0;
	for (int r = 0; r < n; r++)
	{
		if (f[v[r]] == 0)
			u++;
		f[v[r]]++;

		while (u > k)
		{
			f[v[l]]--;
			if (f[v[l]] == 0)
				u--;
			l++;
		}
		
		c += (r - l + 1);
	}
	
	cout << c << endl;
    
    return(0);
}
