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

	int t;
	while (cin >> t and t)
	{
		for (int i = 0; i < t; i++)
		{
			vector<int> v;
			for (int i = 0; i < 5; i++)
			{
				int n; cin >> n;
				if (n <= 127)
					v.push_back(i);
			}

			if (v.size() == 1)
				cout << char('A' + v[0]) << endl;
			else
				cout << '*' << endl;
		}
	}
    
    return(0);
}
