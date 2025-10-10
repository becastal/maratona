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
	vector<vector<int>> a(n);
	for (int i = 0, k; i < n; i++) {
		cin >> k;
		for (int j = 0, x; j < k; j++) {
			cin >> x;
			if (a[i].empty() and x == i + 1) continue;
			a[i].push_back(x);
		}
	}

	if (n == 1 or n >= 3) return cout << "S" << endl, 0;
	if (a[1].empty() and is_sorted(a[0].begin(), a[0].end()) or
		a[0].empty() and is_sorted(a[1].rbegin(), a[1].rend())) return cout << "S" << endl, 0;

	cout << "N" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
