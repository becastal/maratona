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
	while (cin >> n and n)
	{
		vector<pair<int, string>> m;
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			int a, b; cin >> a >> b;

			m.push_back({a - b, s});
		}
		sort(m.begin(), m.end());
		cout << m[0].s << endl;
	}
    
    return(0);
}
