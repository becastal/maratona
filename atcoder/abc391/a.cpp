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

	string s; cin >> s;
	if (s == "N") return cout << "S" << endl, 0;
	if (s == "S") return cout << "N" << endl, 0;
	if (s == "E") return cout << "W" << endl, 0;
	if (s == "W") return cout << "E" << endl, 0;
	if (s == "NE") return cout << "SW" << endl, 0;
	if (s == "SW") return cout << "NE" << endl, 0;
	if (s == "NW") return cout << "SE" << endl, 0;
	if (s == "SE") return cout << "NW" << endl, 0;
    
    return(0);
}
