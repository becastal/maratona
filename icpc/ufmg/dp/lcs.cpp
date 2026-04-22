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

	string s, t; cin >> s >> t;
	vector<vector<int>> l (s.size() + 1, vector<int>(t.size() + 1, 0));

	for (int i = s.size() - 1; i >= 0; i--)
		for (int j = t.size() - 1; j >= 0; j--)
		{
			if (s[i] == t[j])
				l[i][j] = 1 + l[i + 1][j + 1];
			else
				l[i][j] = max(l[i + 1][j], l[i][j + 1]);
		}

	string lcs;
	int i = 0, j = 0;
	while (i < s.size() and j < t.size())
	{
		if (s[i] == t[j])
		{
			lcs.push_back(s[i]);
			i++, j++;
		}
		else if (l[i + 1][j] > l[i][j + 1]) i++;
		else j++;
	}

	cout << lcs << endl;
    
    return(0);
}
