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
		int n; cin >> n;
		int at = 1;
		for (int i = 0; i < n; i++)
		{
			string s = "";
			for (int j = 0; j < n; j++)
			{
				s += (at ? "##" : "..");
				at = !at;
			}
			cout << s << endl << s << endl;
			at = i % 2;
		}
	}
    
    return(0);
}
