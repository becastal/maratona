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

const int MAX = 1e7+10;
int divi[MAX], vis[MAX];
vector<int> primes;

void crivo(int lim) {
	memset(divi, 0, sizeof(divi));
	memset(vis, 0, sizeof(vis));
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
	ll l, r, res = 1; cin >> l >> r;

	crivo(sqrt(r) + 100);
	for (int p : primes) {
		for (ll i = (l / p + 1) * p; i <= r; i += p) {
			if (vis[i - (l + 1)]) continue;
			vis[i - (l + 1)] = 1;
			ll y = i;
			while (y % p == 0) y /= p;
			if (y == 1) res++;
		}
	}
	for (int i = 0; i < r - l; i++) res += !vis[i];
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
