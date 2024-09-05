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

	int n, m; cin >> n >> m;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int ii = 1;
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			ii &= x > 0;
		}
		res += ii;
	}

	cout << res << endl;
    
    return(0);
}
