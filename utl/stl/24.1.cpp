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

	vector<int> v;
	int q; cin >> q;
	while (q--)
	{
		int qi; cin >> qi;
		if (!qi)
		{
			int x; cin >> x;
			v.push_back(x);
		}
		else if (qi == 1)
		{
			
			int x; cin >> x;
			cout << v[x] << endl;
		}
		else
			v.pop_back();
	}
    
    return(0);
}
