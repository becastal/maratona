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
		string n; cin >> n;
		int c = 0;

		while (n != "0")
		{
			if ((n.back() - '0') % 2)
				c++;

			string no;
			int sobe = 0;
			for (auto d : n)
			{
				int agora = sobe * 10 + (d - '0');
				no.push_back(agora / 2 + '0');
				sobe = agora % 2;
			}

			while (no.size() > 1 and no[0] == '0')
				no.erase(no.begin());

			n = no;
		}
		
		cout << c << endl;
	}
    
    return(0);
}
