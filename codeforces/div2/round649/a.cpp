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
	int n, x; cin >> n >> x;
	vector<int> v(n);

	int S = 0, l = -1, r;
	for (int i = 0; i < n; i++) {
		cin >> v[i], S += v[i];
		if (v[i] % x) {
			if (l == -1) l = i;
			r = i;
		}
	}

	if (S % x) {
		cout << n << endl;	
	} else if (l == -1) {
		cout << -1 << endl;	
	} else {
		cout << max(r, n - l - 1) << endl;
	}
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
