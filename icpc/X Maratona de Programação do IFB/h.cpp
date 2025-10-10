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
	ll a, b; char c;
	cin >> a >> c >> b;

	ll I = (a * 60 * 60 * 1000) + (b * 60 * 1000);

	cin >> a >> c >> b;
	ll F = (a * 60 * 60 * 1000) + (b * 60 * 1000);

	ll s, p; cin >> s >> p;
	s *= 1000;

	ll l = lcm(lcm(s, p), 1000);
	cout << (F / l) - (I / l) << endl;

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
