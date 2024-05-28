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

	int n;
	map<char, pair<char, char>> m = {
		{'N', {'O', 'L'}},
		{'L', {'N', 'S'}},
		{'S', {'L', 'O'}},
		{'O', {'S', 'N'}}
	};

	while (cin >> n and n)
	{
		char dir = 'N';
		for (int i = 0; i < n; i++)
		{
			char mov; cin >> mov;
			if (mov == 'E')
				dir = m[dir].f;
			else
				dir = m[dir].s;
		}
		cout << dir << endl;
	}
    
    return(0);
}
