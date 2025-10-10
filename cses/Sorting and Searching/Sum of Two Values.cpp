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
 
	int n, x; cin >> n >> x;
 
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> v[i].f;
		v[i].s = i + 1;
	}
 
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	while (l < r)
	{
		int soma = v[l].f + v[r].f;
		if (soma == x)
			return cout << v[l].s << ' ' << v[r].s << endl, 0;
		else if (soma < x)
			l++;
		else if (soma > x)
			r--;
	}
 
	cout << "IMPOSSIBLE" << endl;
 
    return(0);
}
