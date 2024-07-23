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
		int x1, x2, x3; 
		cin >> x1 >> x2 >> x3; 

		int d = INF;
		for (int i = 0; i <= 10; i++)
			d = min(d, abs(x1 - i) + abs(x2 - i) + abs(x3 - i));
		cout << d << endl;
	}
	
    
    return(0);
}
