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
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	vector<ll> p = a, s = a;

	for (int i = 1; i < n; i++) {
		p[i] += p[i-1];
	}

	for (int i = n-2; i >= 0; i--) {
		s[i] += s[i+1];
	}

	for (int i = 1; i < n-1; i++) {
		if (p[i-1] == s[i+1]) return cout << i+1 << endl, 0;
	}

	cout << "A cadeira, usa a cadeira!" << endl;

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
