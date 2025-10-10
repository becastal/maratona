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
	vector<int> v(n), pre(n+1, 0), bom(n+1, 0);

	for (int& i : v) cin >> i;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (pre[j] - pre[i-1] <= n) bom[pre[j]-pre[i-1]] = 1;
			else break;
		}
	}

	int res = 0;
	for (int i : v) res += bom[i];
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
