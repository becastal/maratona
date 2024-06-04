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
		string s; cin >> s;

		int melhor = INF, n = s.size();
		vector<pair<char, int>> v;
		for (auto c : s)
		{
			if (v.empty() or v.back().f != c)
				v.push_back({c, 1});
			else
				v.back().s++;
		}
		int m = v.size();
		for (int i = 1; i < m - 1; i++)
			if (v[i - 1].f != v[i + 1].f)
				melhor = min(melhor, v[i].s + 2);

		if (melhor > n)
			melhor = 0;

		cout << melhor << endl;
	}
    
    return(0);
}
