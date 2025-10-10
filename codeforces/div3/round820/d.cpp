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
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		v[i] = x - v[i];
	}

	sort(v.begin(), v.end());
	//for (int i : v) cout << i << ' '; cout << endl;

	int res = 0;
	for (int r = n-1, l = 0; r > l; r--) {
		while (l < r and v[r] + v[l] < 0) l++;
		if (l < r) res++, l++;
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
