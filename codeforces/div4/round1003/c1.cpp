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
	int n, m; cin >> n >> m;

	vector<int> a(n), b(m);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	int ok = 1, ult = -INF;
	for (int i = 0; i < n and ok; i++) {
		int ai = a[i], bi = b[0] - a[i];
			
		if (min(ai, bi) >= ult) {
			ult = min(ai, bi);
		} else if (max(ai, bi) >= ult) {
			ult = max(ai, bi);
		} else {
			ok = 0;
		}
	}

	cout << (ok ? "YES" : "NO") << endl;
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
