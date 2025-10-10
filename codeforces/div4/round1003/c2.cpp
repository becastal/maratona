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
	int n, m; cin >> n >> m;

	vector<int> a(n), b(m);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	sort(b.begin(), b.end());

	int ok = 1, ult = -INF;
	for (int i = 0; i < n and ok; i++) {
		int agr = INF;

		if (a[i] >= ult) {
			agr = min(agr, a[i]);
		}

		auto it = lower_bound(b.begin(), b.end(), ult + a[i]);
		if (it != b.end()) {
			agr = min(agr, *it - a[i]);
		}

		if (agr == INF) ok = 0;
		ult = agr;	
	}

	cout << (ok ? "YES" : "NO") << endl;
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
