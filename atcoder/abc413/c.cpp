#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	queue<pair<int, int>> q;

	while (n--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int c, x; cin >> c >> x; 
			q.emplace(c, x);
		} else {
			int k; cin >> k;
			ll s = 0;
			while (k) {
				int t = min(k, q.front().f);

				q.front().f -= t;
				k -= t;
				s += ll(t) * q.front().s;
				if (!q.front().f) q.pop();
			}
			cout << s << endl;
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
