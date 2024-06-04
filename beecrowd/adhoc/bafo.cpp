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

	int r, t = 0;
	while (cin >> r and r)
	{
		cout << "Teste " << ++t << endl;
		pair<int, int> p = {0, 0};
		while (r--)
		{
			int a, b; cin >> a >> b;
			p.f += a, p.s += b;
		}
		cout << (p.f > p.s ? "Aldo" : "Beto") << endl << endl;
	}
    
    return(0);
}
