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

	int d; cin >> d;
	if (d >= 10) return cout << "1 2 3" << endl, 0;
	if (d == 1) return cout << "2 12 100" << endl, 0;
	if (d == 3) return cout << "1 12 100" << endl, 0;
	cout << "1 27 100" << endl;
	
    
    return(0);
}
