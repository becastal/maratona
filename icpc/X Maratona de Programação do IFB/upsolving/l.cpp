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
	int n, x; cin >> n >> x;

	vector<int> a(n), q(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> q[i];
	}

	vector<int> res(n+1, 0);
	for (int i = 0; i < (1 << n); i++) {
		int xi = 0, ai = 0;

		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j))) continue;
			xi += a[j];
			ai += q[j];
		}

		if (xi <= x) res[__builtin_popcount(i)] = max(res[__builtin_popcount(i)], ai);
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << " \n"[i==n];
	}

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
