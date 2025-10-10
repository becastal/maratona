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
	while (t--) {
		int r, g, b, w; 
		cin >> r >> g >> b >> w; 

		int ok = (r&1)+(g&1)+(b&1)+(w&1) <= 1;
		if (r and g and b) ok |= ((r-1)&1)+((g-1)&1)+((b-1)&1)+((w+3)&1) <= 1;
	
		cout << (ok ? "Yes" : "No") << endl;
	}
    
    return(0);
}
