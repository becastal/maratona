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

	int res = 0, tam = 0, ok = 1;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (tam + (int)s.size() > m) ok = 0;

		if (ok and tam + (int)s.size() <= m) {
			tam += (int)s.size();
			res++;
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
