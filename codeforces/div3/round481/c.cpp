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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<ll> v(n), pre(n+1, 0);
	for (ll& i : v) cin >> i;

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1];
	}

	for (int i = 0; i < m; i++) {
		ll x; cin >> x;

		auto it = lower_bound(pre.begin(), pre.end(), x);
		it--;

		cout << it - pre.begin() + 1 << ' ' << x - *it << endl;
	}
    
    return(0);
}

