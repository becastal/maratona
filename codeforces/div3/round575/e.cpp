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
    int b, w; cin >> b >> w;
	
	vector<pair<int, int>> res;
	int dif = 0;
	if (b < w) swap(w, b), dif = 1;

	int x = 2, y = 2;
	while (w > 0) {
		res.emplace_back(x, y);
		(x + y) & 1 ? b-- : w--;
		y++;
	}

	int cx = 1, cy = 2;
	while (b > 0 and cy <= y) {
		res.emplace_back(cx, cy);
		b--;
		cy += 2;
	}
	cx = 3, cy = 2;
	while (b > 0 and cy <= y) {
		res.emplace_back(cx, cy);
		b--;
		cy += 2;
	}
	if (b > 0) {
		res.emplace_back(2, 1);
		b--;
	}
	if (b > 0) {
		res.emplace_back(2, y);
		b--;
	}
	if (b > 0) {
		cout << "NO" << endl;
	} else {
		assert(w == 0);
		cout << "YES" << endl;	
		for (auto [a, b] : res) {
			cout << a << ' ' << b + dif << endl;
		}
	}
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
