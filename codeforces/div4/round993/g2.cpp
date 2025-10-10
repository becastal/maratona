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
	vector<int> v(n), in(n, 0), c(n, 0);
	for (int& i : v) cin >> i, in[--i]++;
	set<int> nodos;

	queue<int> q;
	for (int i = 0; i < n; i++) {
		nodos.insert(i);
		if (!in[i]) q.push(i);
	}

	while (q.size()) {
		int u = q.front(); q.pop();
		nodos.erase(u);
		
		if (--in[v[u]] == 0) q.push(v[u]);
		c[v[u]] += c[u]+1;
	}

	int res = 2;
	for (int i = 0; i < n; i++) {
		if (!nodos.count(i)) {
			res = max(res, c[i]+3);
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
