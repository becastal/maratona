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

string s, t, lcs;
int l[3010][3010];

recupera(int i, int j)
{
	if (i >= s.size() or j >= t.size()) return;
	if (s[i] == t[j])
	{
		lcs.push_back(s[i]);
		recupera(i + 1, j + 1);
	}
	
	if (l[i + 1][j] >= l[i][j + 1])
		recup
}

int main()
{
    _;

	cin >> s >> t;

	for (int i = s.size() - 1; i >= 0; i--)
		for (int j = t.size() - 1; j >= 0; j--)
		{
			if (s[i] == t[j])
				l[i][j] = 1 + l[i + 1][j + 1];
			else
				l[i][j] = max(l[i + 1][j], l[i][j + 1]);
		}

	cout << lcs << endl;
    
    return(0);
}
