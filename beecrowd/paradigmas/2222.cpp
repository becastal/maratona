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

	vector<bitset<64>> v(n);
	for (int i = 0, m; i < n; i++) {
		cin >> m;
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			v[i][x] = 1;
		}
	}

	int q; cin >> q;
	bitset<64> a;
	while (q--) {
		int tp, x, y; cin >> tp >> x >> y; x--, y--;
		if (tp == 1) a = v[x] & v[y];
		else a = v[x] | v[y];
		cout << a.count() << endl;
	}
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
