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

	int p, r; cin >> p >> r;

	if (p and r)
		cout << 'A' << endl;
	else if (!p)
		cout << 'C' << endl;
	else
		cout << 'B' << endl;
    
    return(0);
}