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

int t;
int n, m;

string solve()
{
	int x, y; cin >> x >> y;

	if (x == n or y == m)
		return "divisa";

	string resp = "";

	resp += (y > m ? 'N' : 'S');
	resp += (x > n ? 'E' : 'O');

	return resp;
}

int main()
{
    _;

	while (cin >> t and t)
	{
		cin >> n >> m;
		for (int i = 0; i < t; i++)
			cout << solve() << endl;
	}
    
    return(0);
}
