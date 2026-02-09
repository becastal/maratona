#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 3e6+10;
int divi[MAX];
vector<ll> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int solve() {
	ll n; cin >> n;
	int m = (int)primes.size(), res = 0;

	for (int i = 0; i < m; i++) {
		__int128_t p = primes[i] * primes[i];
		if (p > n) break;
		for (int j = i + 1; j < m; j++) {
			__int128_t p_ = p * primes[j];
			if (p_ > n) break;
			for (int k = j + 1; k < m; k++) {
				__int128_t p__ = p_ * primes[k] * primes[k];
				if (p__ > n) break;
				res++;
			}
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

