#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll n, m, d; cin >> n >> m >> d;
	vector<ll> A(n), B(m);
	for (ll& i : A) cin >> i;
	for (ll& i : B) cin >> i;
	sort(all(A));
	sort(all(B));

	ll res = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		auto it = upper_bound(all(B), A[i] + d);
		if (it == B.begin() or llabs(A[i] - *prev(it)) > d) continue;
		res = max(res, A[i] + *prev(it));
	}

	cout << (res == LLONG_MIN ? -1LL : res) << endl;

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

