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
	
	int l, n; cin >> l >> n;
	map<string, string> m;

	for (int i = 0; i < l; i++)
	{
		string a, b; cin >> a >> b;
		m.insert({a, b});
	}

	for (int i = 0; i < n; i++)
	{
		string q; cin >> q;
		if (m.find(q) != m.end())
			cout << m[q] << endl;
		else if (
				q[q.size() - 2] != 'a' and 
				q[q.size() - 2] != 'e' and 
				q[q.size() - 2] != 'i' and 
				q[q.size() - 2] != 'o' and 
				q[q.size() - 2] != 'u' and 
				q[q.size() - 1] == 'y'
				)
		{
			q[q.size() - 1] = 'i';
			q += "es";
			cout << q << endl;
		}
		else if (
				q[q.size() - 1] == 'o' or 
				q[q.size() - 1] == 's' or 
				q[q.size() - 1] == 'x' or 
				(q[q.size() - 1] == 'h' and (q[q.size() - 2] == 's' or q[q.size() - 2] == 'c'))
				)
		{
			q += "es";
			cout << q << endl;
		}
		else
			cout << q << 's' << endl;

	}
    
    return(0);
}
