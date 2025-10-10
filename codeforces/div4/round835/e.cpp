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
    vector<int> v(n);
    for (int& i : v) cin >> i;

	auto f = [](vector<int> a) {
		ll zeros = 0, res = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			if (!a[i]) zeros++;
			else res += zeros;
		}
		return res;
	};
	ll res = f(v);

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			v[i] = 1;
			res = max(res, f(v));
			v[i] = 0;
			break;
		}
	}

	for (int i = n-1; i >= 0; i--) {
		if (v[i]) {
			v[i] = 0;
			res = max(res, f(v));
			break;
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
