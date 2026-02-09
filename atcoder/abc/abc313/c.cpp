#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	ll s = 0;
	vector<ll> A(n);
	for (ll& i : A) {
		cin >> i;
		s += i;
	}

	ll a = s / n, b = a + 1;
	ll qb = s % n, qa = n - qb;

	ll res = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > a) res += A[i] - a;
		cb += A[i] >= b;
	}

	cout << res - min(cb, qb) << endl;

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

