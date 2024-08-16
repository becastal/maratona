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
	set<int> s;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		s.insert(x);
	}

	if (s.size() == 2 and *s.rbegin() - *s.begin() > 1) return cout << "YES" << endl, 0;
	cout << "NO" << endl;
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
