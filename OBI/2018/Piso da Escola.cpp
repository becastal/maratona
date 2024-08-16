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

	int l, c; cin >> l >> c;
	if (l == 1 and c == 1) return cout << "1\n0" << endl, 0;
	int t1 = l * c + (l - 1) * (c - 1), t2 = 2 * (l - 1) + 2 * (c - 1);
	cout << t1 << endl << t2 << endl;
    
    return(0);
}
