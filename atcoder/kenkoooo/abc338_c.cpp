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

	ll n; cin >> n;

	vector<ll> Q(n), A(n), B(n);

	ll maxq = -INF;
	for (ll& i : Q) cin >> i, maxq = max(maxq, i);
	for (ll& i : A) cin >> i;
	for (ll& i : B) cin >> i;

	ll res = 0;
	for (ll i = 0; i <= maxq; i++) {
		ll y = INF;
		for (ll j = 0; j < n; j++) {
			if (Q[j] < A[j] * i) {
				y = -INF;
			} else if (B[j]) {
				y = min(y, (Q[j] - A[j] * i) / B[j]);
			}
		}
		res = max(res, i + y);
	}

	cout << res << endl;
    
    return(0);
}
