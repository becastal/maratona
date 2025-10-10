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
	int n, negs = 0; cin >> n;
	vector<int> v(n);

	ll res = 0;
	for (int& i : v) cin >> i, res += abs(i), negs += i < 0;

	if (negs & 1) {
		sort(v.begin(), v.end(), [&](int a, int b) {
			return abs(a) < abs(b);
		});
		res -= 2 * abs(v[0]);
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
