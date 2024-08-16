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

	int n; cin >> n;
	stack<int> s;
	while (n--)
	{
		string q; cin >> q;	
		if (q == "pop")
		{
			if (s.size() > 0)
			{
				cout << s.top() << endl;
				s.pop();
			}
			else
				cout << "Empty" << endl;
		}
		else
		{
			int x; cin >> x;
			s.push(x);
		}
	}
    
    return(0);
}
