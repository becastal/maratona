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

	int a, b, c, d, e, f;
	int g, h, i, j, k, l;


	cin >> a >> b >> c >> d >> e >> f;
	cin >> g >> h >> i >> j >> k >> l;

	if (max(a, g) >= min(d, j)) return cout << "No" << endl, 0;
	if (max(b, h) >= min(e, k)) return cout << "No" << endl, 0;
	if (max(c, i) >= min(f, l)) return cout << "No" << endl, 0;

	cout << "Yes" << endl;
    
    return(0);
}

