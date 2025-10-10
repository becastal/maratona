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
	vector<int> a(n), b(n), c(n);

	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
		s += a[i];
	}

	sort(c.rbegin(), c.rend());
	if (s <= m) return cout << 0 << endl, 0;
	for (int i = 0; i < n; i++) {
		if (s - c[i] <= m) return cout << i+1 << endl, 0;
		s -= c[i];
	}
	cout << -1 << endl;
    
    return(0);
}
