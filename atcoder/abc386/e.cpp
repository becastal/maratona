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

int main()
{
    _;

	int n, k; cin >> n >> k;
	ll xs = 0;

	vector<ll> v(n), esc(n, 0);
	for (ll& i : v) cin >> i, xs ^= i;

	if (n == k) return cout << xs << endl, 0;

	ll res = 0;
	auto f = [&](auto f, ll x, int i, int c) -> void {
		if (!c) {
			res = max(res, x);
			return;
		}

		if (i == n) return;

		f(f, x ^ v[i], i+1, c-1);
		f(f, x, i+1, c);
	};

	if (k <= n - k) {
		f(f, 0, 0, k);
	} else {
		f(f, xs, 0, n-k);
	}

	cout << res << endl;
    
    return(0);
}
