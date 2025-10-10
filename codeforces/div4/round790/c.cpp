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
	int n, m; cin >> n >> m;
	vector<string> v(n);
	for (auto& i : v) cin >> i;

	int res = INF;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int agr = 0;

			for (int ii = 0; ii < m; ii++) {
				agr += abs(v[i][ii] - v[j][ii]);
			}
			res = min(res, agr);
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
