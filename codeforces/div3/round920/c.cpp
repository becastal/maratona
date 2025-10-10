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
	ll n, f, a, b; cin >> n >> f >> a >> b;

	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	for (int i = 0, ult = 0; i < n and f > 0; ult = A[i++]) {
		ll mn = min((A[i] - ult) * a, b);
		f -= mn;
	}

	cout << (f > 0 ? "YES" : "NO") << endl;

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
