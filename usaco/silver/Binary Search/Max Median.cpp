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
	int n, k; cin >> n >> k;

	int l = INF, r = -INF;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
		l = min(l, i);
		r = max(r, i);
	}

	auto da = [&](int m) {
		vector<int> b(n+1, 0);
		for (int i = 1; i <= n; i++) {
			b[i] = b[i-1] + (a[i-1] >= m ? +1 : -1);
		}
		
		for (int i = k, s = 0; i <= n; i++) {
			s = min(s, b[i-k]);
			if (b[i] - s >= 1) return 1;
		}
		return 0;
	};

	int res = l;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			res = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
