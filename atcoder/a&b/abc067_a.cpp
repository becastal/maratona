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
	if (a % 3 == 0 or b % 3 == 0 or (a + b) % 3 == 0) return cout << "Possible" << endl, 0;
	cout << "Impossible" << endl;
    
    return(0);
}
