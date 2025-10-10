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

	double l; cin >> l;
	int tot = 1;
	while (l >= 2.0)
	{
		l /= 2;
		tot *= 4;
	}

	cout << tot << endl;
    
    return(0);
}
