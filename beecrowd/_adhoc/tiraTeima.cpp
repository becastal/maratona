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

	pair<pair<int, int>, pair<int, int>> r = { {0, 0}, {432, 468} };

	int x, y; cin >> x >> y;
	cout << (x >= r.f.f and y >= r.f.s and x <= r.s.f and y <= r.s.s ? "dentro" : "fora") << endl;
    
    return(0);
}
