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

	int n, c, t; cin >> n >> c >> t;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	auto da = [&] (ll m) {
		int cont = 1;
		ll total = t * m;
		for (int i = 0; i < n; i++) {
			if (total >= v[i]) {
				total -= v[i];
			} else {
				cont++;
				total = t * m;
				i--;
			}
			if (cont > c) return 0;
		}
		return 1;
	};

	int l = 0, r = 1e9 + 10;
	while (l < r) {
		int m = (l + r) / 2;
		if (da(m)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << l << endl;
    
    return(0);
}
