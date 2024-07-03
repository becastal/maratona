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

map<char, char> d = {
	{'J', 'F'},
	{'j', 'f'},
	{'P', 'F'},
	{'p', 'f'},
	{'V', 'F'},
	{'v', 'f'},
	{'B', 'F'},
	{'b', 'f'},
	{'S', 'F'},
	{'s', 'f'},
	{'X', 'F'},
	{'x', 'f'},
	{'Z', 'F'},
	{'z', 'f'},
};

int main()
{
    _;

	string s;
	while (getline(cin, s))
	{
		queue<char> q;
		for (char c : s)
		{
			if (d.find(c) != d.end())
				q.push(d[c]);
			else
				q.push(c);
		}
		char ult = 'a';
		while (!q.empty())
		{
			if (q.front() != 'f' and q.front() != 'F')
				cout << q.front(), ult = q.front(), q.pop();
			else if (ult != 'f' and ult != 'F')
				cout << q.front(), ult = q.front(), q.pop();
			else
				q.pop();
		}
		cout << endl;
	}
    
    return(0);
}
