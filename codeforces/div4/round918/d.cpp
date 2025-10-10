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

bool vog(char c)
{
	return c == 'a' or c == 'e';
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		string res = "";
		res.push_back(s[0]);
		
		for (int i = 1; i < n - 1; i++)
		{
			if (vog(s[i]))
				res.push_back(s[i]);
			else if (vog(s[i + 1]))
			{
				if (res.back() != '.') res.push_back('.');
				res.push_back(s[i]);
			}
			else
				res.push_back(s[i]), res.push_back('.');
		}
		
		res.push_back(s[n - 1]);
		cout << res << endl;
	}
    
    return(0);
}
