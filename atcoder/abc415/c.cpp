#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;
	S = "0" + S;

	vector<int> vis(1 << n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		//cout << bitset<3>(u).to_string() << ": " << u << endl;
		for (int v = 0; v < n; v++) if (v != u) {
			if (u & (1 << v) and !vis[u ^ (1 << v)] and S[u ^ (1 << v)] != '1') {
				dfs(u ^ (1 << v));
			}
		}
	};

	if (S[(1 << n)-1] != '1') dfs((1 << n) - 1);

	cout << (vis[0] ? "Yes" : "No") << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
