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
	int n, d; cin >> n;
	ll c; cin >> c >> d;

	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.rbegin(), v.rend());

	auto da = [&](int k) {
		ll agr = 0;	
		for (int i = 0; i < d; i++) {
			if (i % k < n) {
				agr += v[i % k];
			}
		}

		return agr >= c;
	};

	if (!da(1)) {
		cout << "Impossible" << endl;
		return;
	}

	int l = 1, r = d+10;
	while (l < r) {
		int m = (l + r) / 2;

		if (da(m)) {
			l = m+1;
		} else {
			r = m;
		}
	}

	cout << (l == d+10 ? "Infinity" : to_string(l-2)) << endl;
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
