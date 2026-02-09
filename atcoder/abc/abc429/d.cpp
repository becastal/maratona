#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*


*/

int solve() {
	ll n, m, c; cin >> n >> m >> c;

	vector<ll> A(n);
	map<ll, int> F;
	for (ll& i : A) {
		cin >> i;
		F[i]++;
	}

	vector<pair<ll, int>> B;
	for (auto [a, b] : F) {
		B.emplace_back(a, b);
	}

	int nn = (int)B.size();
	vector<ll> tam(nn);
	for (int i = 0; i < nn; i++) {
		int j = (i - 1 + nn) % nn;
		ll d = (B[i].first - B[j].first) % m;
		if (d < 0) d += m;
		if (!d) d = m;
		tam[i] = d;
	}
		
	ll res = 0;
	for (ll l = 0, r = 0, s = B[0].second; l < nn; l++) {
		while (s < c) {
			s += B[r = (r + 1) % nn].second;
		}
		res += tam[l] * s;

		s -= B[l].second;
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

