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

char solve()
{
	int cv, ce, cs; cin >> cv >> ce >> cs;
	int fv, fe, fs; cin >> fv >> fe >> fs;

	int cp = cv * 3 + ce;
	int fp = fv * 3 + fe;

	if (cp == fp)
		if (cs == fs)
			return '=';
		else 
			return (cs > fs ? 'C' : 'F');

	return (cp > fp ? 'C' : 'F');
}

int main()
{
    _;

	cout << solve() << endl;
    
    return(0);
}
