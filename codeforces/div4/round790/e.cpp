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
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.rbegin(), v.rend());

	vector<ll> pre(n+1, 0);	
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1];
	}

	for (int i = 0, x; i < q; i++) {
		cin >> x;

		auto it = lower_bound(pre.begin(), pre.end(), x);

		cout << (it == pre.end() ? -1 : it - pre.begin()) << endl;
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
