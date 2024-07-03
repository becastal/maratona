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

	string s;
	while (getline(cin, s))
	{
		if (!s.size()) continue;
		vector<int> c;
		int val = 0, cont = 2;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
				val += (s[i] - '0') * pow(8, cont--);
			else
			{
				c.push_back(val);
				val = 0;
				cont = 2;
			}
		}
		c.push_back(val);
		for (int i : c)
		{
			if (i >= 129 and i <= 137) cout << char('a' + (i - 129));
			else if (i >= 145 and i <= 153) cout << char('j' + (i - 145));
			else if (i >= 162 and i <= 169) cout << char('s' + (i - 162));
			else if (i >= 193 and i <= 201) cout << char('A' + (i - 193));
			else if (i >= 209 and i <= 217) cout << char('J' + (i - 209));
			else if (i >= 226 and i <= 233) cout << char('S' + (i - 226));
			else if (i >= 240 and i <= 249) cout << char('0' + (i - 240));
			else if (i == 54) cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
    
    return(0);
}
