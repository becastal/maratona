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

set<int> divisores(int n)
{
	set<int> res;
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0)
		{
			res.insert(i);
			res.insert(n / i);
		}
	return res;
}

bool funciona(string& s, int l)
{
	string pre = "", pos = "";	
	for (int i = 0; i < l; i++)
		pre.push_back(s[i]);

	for (int i = (int)s.size() - l; i < (int)s.size(); i++)
		pos.push_back(s[i]);

	int difpre = 0, difpos = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		difpre += s[i] != pre[i % l];
		difpos += s[i] != pos[i % l];
	}

	return difpre <= 1 or difpos <= 1;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		for (int l : divisores(n))
			if (funciona(s, l))
			{
				cout << l << endl;
				break;
			}
	}
    
    return(0);
}
