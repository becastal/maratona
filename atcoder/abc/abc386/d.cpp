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

int main()
{
    _;

	int n, m; cin >> n >> m;

	vector<tuple<int, int, char>> v(m);
	for (int i = 0; i < m; i++) {
		auto& [x, y, c] = v[i];
		cin >> x >> y >> c;
	}
	sort(v.begin(), v.end());

	int min_y = INF;
    
	for (auto [x, y, c] : v) {
		if (c == 'W') {
			min_y = min(min_y, y);
		} else {
			if (y >= min_y) return cout << "No" << endl, 0;
		}
	}

	cout << "Yes" << endl;
    return(0);
}
