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

vector<int> div(int n) {
	vector<int> res;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);	
			if (n / i != i) res.push_back(n / i);
		}
	}
	return res;
}

int solve() {
	int l, r; cin >> l >> r;
	if (r <= 3) return cout << -1 << endl, 0;

	if (l == r) {
		auto divi = div(l);
		if (divi.empty()) return cout << -1 << endl, 0;
		cout << divi[0] << ' ' << l - divi[0] << endl;
	} else {
		cout << (r-(r&1))/2 << ' ' << (r-(r&1))/2 << endl;
	}
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
