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
	string s; cin >> s;

	map<pair<int, int>, int> vis;
	pair<int, int> agr = {0, 0};
	
	vis[agr] = 0;
	int tam = INF, l = -1, r = n, i = 0;
	for (char c : s) {
		if (c == 'R') agr.s++;
		if (c == 'L') agr.s--;
		if (c == 'D') agr.f++;
		if (c == 'U') agr.f--;

		if (vis.count(agr)) {
			if (tam > i - vis[agr] + 1) {
				tam = i - vis[agr] + 1;
				l = vis[agr];
				r = i;
			}
		}
		vis[agr] = ++i;
	}

	if (tam == INF) { cout << -1 << endl; return; }
	cout << l+1 << ' ' << r+1 << endl;
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
