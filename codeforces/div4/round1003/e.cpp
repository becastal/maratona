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
	int n, m, k; cin >> n >> m >> k;

	if (abs(n - m) > k or max(n, m) < k) return cout << -1 << endl, 0;

	string res = "";
	while (1) {
		if (!n or !m or max(n, m) == k) break;
		res.push_back('0');
		res.push_back('1');
		n--, m--;
	}

	if (!n) {
		res = string(m-k+1, '1') + res + string(k-1, '1');
	} else if (!m) {
		res = string(k-1, '0') + res + string(n-k+1, '0');
	} else {
		res = string(m, '1') + res + string(n, '0');
	}

	cout << res << endl;

	return 0;
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
