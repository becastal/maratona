#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;
	sort(all(A));

	ll res = LINF;
	if (A[n-1] > A[n-2]) res = A[n-1];

	for (int i = 0; i < n; i++) {
		auto it = upper_bound(A.begin() + i + 1, A.end(), A[n-1] - A[i]); 

		if (it == A.end()) continue;
		//cout << A[i] << ' ' << *it << endl;
		res = min(res, A[i] + *it);
	}

	if (res == LINF) return cout << -1 << endl, 0;
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
