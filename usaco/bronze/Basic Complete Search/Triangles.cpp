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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("triangles");

	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (auto& [x, y] : p) cin >> x >> y;

	ll res = 0;
	for (auto [x1, y1] : p) {
		for (auto [x2, y2] : p) {
			if (x1 != x2 or y1 == y2) continue;
			for (auto [x3, y3] : p) {
				if (y1 != y3 or x1 == x3) continue;
				
				res = max(res, (ll)abs(y2 - y1) * (ll)abs(x3 - x1));
			}
		}
	}
	cout << res << endl;

    return(0);
}
