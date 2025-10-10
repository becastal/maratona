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

int primo(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main()
{
    _;

	const ll MAX = 1e12+10;
	set<ll> sim;
	for (ll i = 2; i * i <= MAX; i++) {
		if (primo(i)) sim.emplace(i*i);
	}

	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		cout << (sim.count(x) ? "YES" : "NO") << endl;
	}
    
    return(0);
}
