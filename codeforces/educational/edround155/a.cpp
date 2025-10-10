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

	for (auto& [s, e] : v) {
		cin >> s >> e;	
	}

	auto [si, ei] = v[0];

	bool res = 1;	
	for (int i = 1; i < n and res; i++) {
		if (v[i].f >= si and v[i].s >= ei) res = 0;
	}

	cout << (res ? si : -1) << endl;
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
