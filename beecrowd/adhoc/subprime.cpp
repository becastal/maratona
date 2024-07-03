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

	int b, n;
	while (cin >> b >> n and b and n)
	{
		vector<int> bancos(b);
		for (int& bi : bancos)
			cin >> bi;

		while (n--)
		{
			int d, c, v; cin >> d >> c >> v;
			d--, c--;
			bancos[d] -= v, bancos[c] += v;
		}

		bool res = true;
		for (int i : bancos)
			res = res and i >= 0;

		cout << (res ? 'S' : 'N') << endl;
	}
    
    return(0);
}
