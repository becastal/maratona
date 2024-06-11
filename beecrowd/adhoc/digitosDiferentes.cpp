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

bool digunicos(int i)
{
	vector<int> v(10);
	string s = to_string(i);
	for (auto c : s)
	{
		if (v[c - '0'])
			return false;
		v[c - '0']++;
	}
	return true;
}

int main()
{
    _;

	int n, m;
	while (cin >> n >> m)
	{
		int c = 0;
		for (int i = n; i <= m; i++)
			if (digunicos(i))
				c++;
		cout << c << endl;
	}
    
    return(0);
}
