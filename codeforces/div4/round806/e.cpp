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
	vector<string> v(n);
	for (auto& i : v) cin >> i;

	auto pos = [&](int i, int j) {
		set<pair<int, int>> s;
		s.emplace(i, j);
		s.emplace(j, n-1-i);
		s.emplace(n-1-i, n-1-j);
		s.emplace(n-1-j, i);
		return s;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '#') continue;
			vector<int> cont(2, 0);
			int tot = 0;
			for (auto [ii, jj] : pos(i, j)) {
				cont[v[ii][jj]-'0']++;	
				v[ii][jj] = '#';
				tot++;
			}
			res += tot - max(cont[0], cont[1]);	
		}
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
