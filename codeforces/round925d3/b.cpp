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

void solve() {
	int n; cin >> n;
	ll tot = 0, m, amais = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i, tot += i;
	m = tot / n;

	int da = 1;
	for (int i = 0; i < n and da; i++) {
		v[i] -= m;
		amais += v[i];	
		da &= amais >= 0;
	}
	cout << (da ? "yes" : "no") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
