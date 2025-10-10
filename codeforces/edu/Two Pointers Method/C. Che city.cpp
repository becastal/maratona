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
	int n, R; cin >> n >> R;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	ll res = 0;
	for (ll l = 0, r = 0; l < n; l++) {
		while (r < n and A[r] - A[l] <= R) {
			r++;
		}
		if (A[r] - A[l] <= R) break;

		res += (n - r);
	}
	cout << res << endl;

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
