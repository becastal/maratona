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

void solve() {
	int n; cin >> n;
	vector<int> cont(2, 0);

	vector<vector<int>> pt(n+1, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		cont[y]++;
		pt[x][y] = 1;
	}
	
	ll res = 0;
	for (int y = 0; y <= 1; y++) {
		for (int x = 0; x <= n; x++) {
			if (pt[x][y] and pt[x][y^1]) {
				res += cont[y]-1;
			}
			if (pt[x][y] and x >= 1 and pt[x-1][y^1] and x < n and pt[x+1][y^1]) {
				res++;
			}
		}
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
