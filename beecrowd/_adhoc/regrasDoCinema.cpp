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

	int a, b; cin >> a >> b;
	cout << ((a >= 6 and b >= 6) and ((a >= 18 or b >= 18) or (a >= 14 and b >= 14)) ? "YES" : "NO") << endl;
    
    return(0);
}
