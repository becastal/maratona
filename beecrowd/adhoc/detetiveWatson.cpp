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
		vector<pair<int, int>> maior(n);

		for (int i = 0; i < n; i++)
		{
			cin >> maior[i].f;
			maior[i].f = -maior[i].f;
			maior[i].s = i + 1;
		}

		sort(maior.begin(), maior.end());

		cout << maior[1].s << endl;
	}
    
    return(0);
}
