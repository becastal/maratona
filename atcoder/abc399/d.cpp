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
	// (..., a, b, ..., a, b, ...);
	// (..., a, b, ..., b, a, ...);
	int n; cin >> n;
	vector<int> v(2*n);
	vector<vector<int>> pos(n+1);
	for (int i = 0; i < 2*n; i++) {
		cin >> v[i];
		pos[v[i]].push_back(i);
	}

	set<pair<int, int>> s;
	for (int i = 0; i < 2*n-1; i++) {
		int a = v[i], b = v[i+1];

		if (pos[a][0]+1 == pos[a][1]) continue;
		if (pos[b][0]+1 == pos[b][1]) continue;

		vector<int> vi = {pos[a][0], pos[a][1], pos[b][0], pos[b][1]};
		sort(vi.begin(), vi.end());
		if (vi[0] + 1 == vi[1] and vi[2]+1 == vi[3]) {
			s.emplace(minmax(a, b));
		}
	}
	cout << s.size() << endl;
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
