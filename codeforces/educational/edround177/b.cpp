#include <bits/stdc++.h>
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

int solve() {
	ll n, k, x; cin >> n >> k >> x;
	vector<ll> A(n), B;
	for (ll& i : A) cin >> i;

	for (int rep : {0, 1}) for (ll i : A) B.push_back(i);
	vector<ll> PB(2*n+1, 0);
	for (int i = 1; i <= 2*n; i++) {
		PB[i] = PB[i-1] + B[i-1];
	}

	ll s = accumulate(all(A), 0LL);
	ll ciclos = (s < x ? ((x - s) + s - 1) / s : 0);
	ll quero = x - ciclos * s;
	if (s * k < x) return cout << 0 << endl, 0;

	ll res = 0;
	for (int l = 0, r = 1; l < n; l++) {
		r = max(r, l+1);
		while (r <= l + n and PB[r] - PB[l] < quero) r++;

		ll tam = ciclos * n + (r - l - 1);
		ll add = n * k - (l + 1) - tam;
		if (add >= 0) res += add / n + 1;
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
