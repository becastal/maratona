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

	int t; cin >> t;
	while (t--)
	{
		int n, pos = 0; cin >> n;
		vector<int> v(n, 0);
		
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;

			if (s == "LEFT")
				v[i] = -1;
			else if (s == "RIGHT")
				v[i] = 1;
			else
			{
				int j;
				cin >> s >> j;
				v[i] = v[j - 1];
			}
			pos += v[i];
		}

		cout << pos << endl;
	}
    
    return(0);
}
