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

struct DSU {
	vector<int> id, d;
	DSU(int n) : id(n), d(n, 0) {
		iota(all(id), 0);
	}

	int find(int i) {
		vector<int> cam;
		int u = i, res = 0;
		while (u != id[u]) {
			cam.push_back(u);
			u = id[u];
		}

		for (int i : cam) res += d[i];

		int s = res;
		for (int v : cam) {
			int d_ = d[v];
			id[v] = u;
			d[v] = s;
			s -= d_;
		}

		return res;
	}

	void merge(int i, int j) {
		id[i] = j;
		d[i] = 1;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	DSU dsu(n);

	while (m--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int a, b; cin >> a >> b; a--, b--;
			dsu.merge(a, b);
		} else {
			int c; cin >> c; c--;
			cout << dsu.find(c) << endl;
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
