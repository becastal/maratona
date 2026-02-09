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

pair<ll, ll> f(ll a, ll b, ll c, ll d) {
	ll n = a / b;
	a -= n * b, c -= n * d;
	if (c > d)
		return {n + 1, 1};
	auto [p, q] = f(d, c, b, a);
	return {p * n + q, p};
}

int solve() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	auto [p, q] = f(A, B, C, D);

	cout << q << endl;
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
