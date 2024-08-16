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
	vector<pair<int, int>> v(n);
	for (auto& [a, b] : v) cin >> a;
	for (auto& [a, b] : v) cin >> b;

	pair<int, int> tot = {0, 0};
	int mais = 0, menos = 0;
	for (auto [a, b] : v) {
		if (a < b) {
			tot.s += b;	
		} else if (a > b) {
			tot.f += a;	
		} else {
			menos += a < 0;
			mais += a > 0;
		}
	}

	int res = -INF;
	for (int i = -menos; i <= mais; i++) {
		res = max(res, min(tot.f + i, tot.s + (mais - menos - i)));
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
