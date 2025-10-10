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
	for (auto& [x, y] : v) cin >> x >> y;

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[i].f < v[j].f and v[i].s > v[j].s) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	
	pair<int, int> agr = {0, 0};
	string res = "";
	for (auto [x, y] : v) {
		int dx = x - agr.f, dy = y - agr.s;
		for (int i = 0; i < dx; i++) {
			res.push_back('R');
		}
		for (int i = 0; i < dy; i++) {
			res.push_back('U');
		}

		agr = {x, y};
	}

	cout << "YES" << endl << res << endl;
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
