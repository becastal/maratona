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

const int MAX = 1000000;
void solve(int n, int m) {
	vector<pair<int, int>> ev;

	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;

		ev.emplace_back(r, 0);
		ev.emplace_back(l, 1);
	}

	for (int i = 0, l, r, rep; i < m; i++) {
		cin >> l >> r >> rep;

		ev.emplace_back(r, 0);
		ev.emplace_back(l, 1);

		while (l + rep < MAX) {
			l += rep, r += rep;
			ev.emplace_back(min(r, MAX), 0);
			ev.emplace_back(l, 1);
		}
	}
	sort(ev.begin(), ev.end());

	int ok = 1, agr = 0;
	for (auto [x, tp] : ev) {
		agr += (tp ? +1 : -1);

		if (agr > 1) {
			ok = 0;
			break;
		}
	}

	cout << (ok ? "NO CONFLICT" : "CONFLICT") << endl;
}


int main()
{
    _;

	int n, m;
	while (cin >> n >> m and (n or m)) {
		solve(n, m);
	}
    
    return(0);
}
