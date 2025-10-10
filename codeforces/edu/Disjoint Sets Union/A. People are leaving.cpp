#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	while (m--) {
		char tp; cin >> tp;
		int x; cin >> x;

		if (tp == '-') {
			s.erase(x);	
		} else {
			auto it = s.lower_bound(x);
			cout << (it == s.end() ? -1 : *it) << endl;
		}
	}

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
