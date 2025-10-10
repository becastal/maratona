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

	map<int, int> M;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		M[x] = i+1;
	}

	int res = -1;
	for (auto [a, i] : M) {
		for (auto [b, j] : M) {
			if (gcd(a, b) == 1) res = max(res, i + j);
		}
	}

	cout << res << endl;
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
