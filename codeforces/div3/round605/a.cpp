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

int solve() {
	int a, b, c; cin >> a >> b >> c;

	ll res = LINF;
	for (int i : {a - 1, a, a + 1}) {
		for (int j : {b - 1, b, b + 1}) {
			for (int k : {c - 1, c, c + 1}) {
				res = min(res, (ll)abs(i - j) + abs(i - k) + abs(j - k));
			}
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
