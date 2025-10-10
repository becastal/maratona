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

vector<ll> divs (ll x) {
	vector<ll> res;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			if (x / i != i) res.push_back(x / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int solve() {
	ll y, k; cin >> y >> k;
	auto d = divs(y);
	ll n = (ll)d.size();

	vector<ll> prox(n, -1), p(n, -1);
	for (ll i = 0; i < n; i++) {
		ll melhor = INF, melhori = -1; 

		for (ll j = i + 1;j < n; j++) {
			if (d[j] % d[i] == 0) { 
				if (d[j] / d[i] < melhor) {
					melhor = d[j] / d[i];
					melhori = j;
				}
			}
		}
		
		prox[i] = melhori;
	}

	ll x = 1, pos = 0;

	while (k) {
		if (prox[pos] == -1 or k <= (d[prox[pos]] / d[pos] - 1)) {
			x += d[pos] * k;
			break;
		}

		k = max(0LL, k - (d[prox[pos]] / d[pos] - 1));
		pos = prox[pos];
		x = d[pos];
	}

	cout << x << endl;

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
