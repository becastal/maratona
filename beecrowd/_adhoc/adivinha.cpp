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
	while (n--)
	{
		int qt, s; cin >> qt >> s;

		vector<pair<int, int>> v(qt);
		
		for (int i = 0; i < qt; i++)
		{
			int qti; cin >> qti;
			v[i].f = abs(s - qti);
			v[i].s = i + 1;
		}

		sort(v.begin(), v.end());

		cout << v[0].s << endl;
	}
    
    return(0);
}
