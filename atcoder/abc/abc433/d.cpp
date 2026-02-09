#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<ll> A(n);
	vector<map<ll, ll>> M(15);

	auto tam = [](ll a) {
		ll r = 0;
		while (a) {
			r++;
			a /= 10;
		}
		return r;
	};

	for (ll& i : A) {
		cin >> i;
		M[tam(i)][i % m]++;
	}

	vector<ll> pot(15, 1);
	for (ll i = 1; i < 15; i++) {
		pot[i] = pot[i-1] * 10;
	}

	ll res = 0;
	for (ll i : A) {
		//M[tam(i)][i % m]--;	

		for (ll t = 1; t <= 10; t++) {
			ll v = (i % m) * (pot[t] % m) % m;
			res += M[t][(m - v) % m]; 
		}

		//M[tam(i)][i % m]++;
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


