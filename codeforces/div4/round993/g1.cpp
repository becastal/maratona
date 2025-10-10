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
	vector<int> v(n), in(n, 0);
	for (int& i : v) cin >> i, in[--i]++;

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!in[i]) q.push(i);
	}

	int res = 2;
	while (q.size()) {
		int sz = q.size();
		res++;

		while (sz--) {
			int u = q.front(); q.pop();
			if (--in[v[u]] == 0) q.push(v[u]);
		}
	}

	cout << res << endlt
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
