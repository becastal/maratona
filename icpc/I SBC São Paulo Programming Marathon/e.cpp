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
	int n, d; cin >> n >> d;

	vector<pair<int, int>> a(n);
	for (auto& [x, y] : a) {
		cin >> x >> y;
	}
	sort(a.begin(), a.end());

	vector<int> mel(n, 0), dir(n);
	int agr = 0;
	for (int l = 0, r = 0; l < n; ) {
		while (r < n and a[r].f - a[l].f <= d) {
			agr += a[r++].s;
		}

		mel[l] = agr;
		dir[l] = r;

		agr -= a[l++].s;
	}

	vector<int> suf(n+1, 0);
	for (int i = n-1; i >= 0; i--) {
		suf[i] = max(suf[i+1], mel[i]);
	}
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, mel[i] + (dir[i] < n ? suf[dir[i]] : 0));
	}
	cout << res << endl;

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
