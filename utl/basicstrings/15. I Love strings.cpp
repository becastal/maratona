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
		string s, t; cin >> s >> t;
		int i;
		for (i = 0; i < min(s.size(), t.size()); i++)
			cout << s[i] << t[i];
		
		if (i < s.size())
			for (int i; i < s.size(); i++)
				cout << s[i];
		else if (i < t.size())
			for (int i; i < t.size(); i++)
				cout << t[i];
		cout << endl;
	}


    
    return(0);
}
