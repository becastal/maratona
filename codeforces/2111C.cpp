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
	int n; cin >> n;
	vector<int> A(n), pri(n, INF), ult(n, -INF);

	for (int i = 0; i < n; i++) {
		cin >> A[i]; A[i]--;
		pri[A[i]] = min(pri[A[i]], i);
		ult[A[i]] = max(ult[A[i]], i);
	}

	ll res = LINF;
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		while (r < n and A[l] == A[r]) {
			r++;
		}

		res = min(res, (A[l] + 1) * ll(n - (r - l)));
	}

	for (int i = 0; i < n; i++) {
		if (pri[i] == INF) continue;
		res = min(res, (i + 1) * ll(ult[i] + n - pri[i] + 1));
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
