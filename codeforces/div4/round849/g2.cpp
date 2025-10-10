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
	int n, c; cin >> n >> c;
	vector<pair<int, int>> v(n);

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		v[i] = {x + min(i+1, n-i), x+i+1};
	}
	sort(v.begin(), v.end());

	vector<ll> pre(n+1, 0);

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1].f;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		int nc = c - v[i].s;

		int l = 0, r = n, mx = 0;

		while (l <= r) {
			int m = (l + r) / 2;
			ll preco = pre[m];
			int agr = m+1;
            if(m > i) {
                preco-=v[i].f;
                agr--;
            }
            if(preco <= nc) {
                mx = max(agr, mx);
                l = m+1;
            } else {
                r = m-1;
            }
		}
		res = max(res, mx);
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
