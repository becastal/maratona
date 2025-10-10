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

int solve() {
	int n; cin >> n;
	vector<int> v(n), vis(n, 0);

	for (int& i : v) cin >> i, i--;
	set<int> s(v.begin(), v.end());

	if (s.size() != n) return cout << "YES" << endl, 0;


	int ciclos = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		ciclos++;
		
		for (int j = i; !vis[j]; j = v[j]) {
			vis[j] = 1;
		}
	}

	cout << ((n - ciclos) % 2 ? "NO" : "YES") << endl;

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
