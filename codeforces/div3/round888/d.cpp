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
	int n; cin >> n;
	vector<ll> v(n-1);
	for (ll& i : v) cin >> i;
	v.insert(v.begin(), 0);

	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);

	ll sobra = -1;
	for (int i = 1; i < n; i++) {
		ll d = v[i] - v[i-1];
		if (s.count(d)) s.erase(d);
		else {
			if (sobra != -1) return cout << "NO" << endl, 0;
			sobra = d;
		}
	}

	if (sobra == -1 and s.size() == 1) return cout << "YES" << endl, 0;
	if (s.size() == 2 and sobra == (*s.begin() + *s.rbegin())) return cout << "YES" << endl, 0;

	cout << "NO" << endl;
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
