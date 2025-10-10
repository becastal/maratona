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

    ll n, m; 
    cin >> n >> m;

	if (n > m) swap(n, m);

	if (n == 1 and m == 1) return cout << 1 << endl, 0;
	if (n == 1) return cout << (m-2) << endl, 0;
	cout << (n-2)*(m-2) << endl;

    return 0;
}

