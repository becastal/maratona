#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<ll> pre(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1];	
	}

	auto ok = [&](int x) {
		cout << "? " << x << ' ';
		for (int i = 0; i < x; i++) {
			cout << i+1 << " "[i == x-1];
		}
		cout << endl;
		int res; cin >> res;
		return res == pre[x];
	};

	int l = 1, r = n;
	while (l < r) {
		int m = l + r >> 1;

		if (ok(m)) {
			l = m+1;
		} else {
			r = m;
		}
	}
	cout << "! " << l << endl;
}

int main()
{
    //_;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
