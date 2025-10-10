#include <bits/stdc++.h>
// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
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

map<ll, ll> memo;
int solve() {
	ll k; cin >> k;


	auto calc = [&](ll x) {
		if (memo.count(x)) return memo[x];

		ll res = 0, tam = 1, cont = 9, pot = 1;
		while (x >= pot * 10) {
			res += tam * cont;	
			tam++, cont *= 10, pot *= 10;
		}
		res += tam * (x - pot + 1);	

		return memo[x] = res;
	};

	ll l = 1, r = ll(1e18), res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;
		//printf("calc(m: %lld) = %lld\n", m, calc(m));

		if (calc(m) > k) {
			r = m-1;
		} else {
			res = m;
			l = m+1;
		}
	}
	k -= calc(res);

	if (!k) return cout << res % 10 << endl, 0;
	string prox = to_string(res+1);
	cout << prox[k-1] << endl;

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
