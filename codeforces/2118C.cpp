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

int solve() {
	ll n, k, res = 0; cin >> n >> k;
	vector<ll> A(n);
	for (ll& i : A) cin >> i, res += __builtin_popcountll(i);

	for (int j = 0; j <= 60; j++) {
		for (ll i : A) {
			if ((i & (1LL << j)) or k < (1LL << j)) continue;
			res++;
			k -= (1LL << j);
		}
	}
	cout << res << endl;

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
