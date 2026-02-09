#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

x eh sempre um primo
quero saber qual eh o menor primo que nao aparece em algum Ai

*/

const int MAX = 1e7;
int divi[MAX];
vector<int> primes;

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
	int n; cin >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	ll g = accumulate(all(A), 0LL, [&](ll i, ll j) { return gcd(i, j); });

	for (ll i : primes) {
		if (g % i) return cout << i << endl, 0;
	}
	assert(0);
	cout << -1 << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

