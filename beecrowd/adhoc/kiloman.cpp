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
		int t; cin >> t;
		
		vector<pair<int, char>> v(t);

		for (auto& p : v)
			cin >> p.f;

		for (auto& p : v)
			cin >> p.s;

		int cont = 0;
		for (auto& p : v)
			if ((p.s == 'S' and p.f <= 2) or (p.s == 'J' and p.f > 2))
				cont++;

		cout << cont << endl;
	}
    
    return(0);
}
