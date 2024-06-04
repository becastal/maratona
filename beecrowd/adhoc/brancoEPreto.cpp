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

	string s, t;
	while (cin >> s >> t and s != "*" and t != "*")
	{
		vector<int> v(s.size(), 0);
		
		for (int i = 0; i < s.size(); i++)
			if (s[i] != t[i])
				v[i] = 1;

		int c = 0;
		v.push_back(0);
		for (int i = 0; i < v.size() - 1; i++)
			if (v[i] == 1 and v[i + 1] == 0)
				c++;

		cout << c << endl;
	}
    
    return(0);
}
