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

	int v, p; cin >> v >> p;
	
	int r = v % p;
	for (int i = 0; i < p; i++)
		cout << v / p + (r-- > 0 ? 1 : 0) << endl;	
    
    return(0);
}
