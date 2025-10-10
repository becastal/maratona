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

struct DSU {
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};

int main()
{
    _;
	setIO("wormsort");

	int n, m; cin >> n >> m;
	vector<int> p(n);
	for (int& i : p) cin >> i, i--;

	vector<tuple<int, int, int>> ed(m);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}

	if (is_sorted(p.begin(), p.end())) return cout << -1 << endl, 0;
	
	auto da = [&](int mid) {
		DSU dsu(n);
		for (auto& [w, u, v] : ed) {
			if (w < mid) break;
			dsu.merge(u, v);
		}

		int ok = 1;
		for (int i = 0; i < n and ok; i++) {
			ok &= (dsu.find(i) == dsu.find(p[i]));
		}
		return ok;
	};

	sort(ed.rbegin(), ed.rend());
	int l = get<0>(ed[m-1]), r = get<0>(ed[0]), res = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			res = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	cout << res << endl;

    return(0);
}
