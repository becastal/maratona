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
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	int res = 0;
	function<void(int, int, int)> f = [&](int i, int ki, int agr) {
		if (!ki) {
			res = max(res, agr);
			return;
		}
		if (i == n) {
			if (!ki) res = max(res, agr);
			return;
		}
		if (n - i < ki) return;

		f(i+1, ki-1, agr & v[i]);
		f(i+1, ki, agr);
	};

	f(0, k, -1);
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
