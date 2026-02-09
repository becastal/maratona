#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll n, d, p; cin >> n >> d >> p;

	vector<ll> F(n);
	for (ll& i : F) {
		cin >> i;
	}
	sort(all(F));
	vector<ll> P(F);
	for (int i = 1; i < n; i++) {
		P[i] = P[i-1] + F[i];
	}

	ll k = (n + d - 1) / d;
	ll res = p * k;
	for (int i = 0; i < k; i++) {
		res = min(res, P[n-1-(i*d)]+p*i);
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

