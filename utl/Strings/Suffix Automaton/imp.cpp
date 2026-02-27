#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 100000 + 5;

namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26];
	int sz, last;

	void init() {
		sz = 1, last = 0;
		len[0] = 0; link[0] = -1;
		for (int i = 0; i < 26; i++) next[0][i] = 0;
	}

	void add(int c) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		for (int i = 0; i < 26; i++) next[cur][i] = 0;

		int p = last;
		while (p != -1 and !next[p][c]) {
			next[p][c] = cur;
			p = link[p];
		}

		if (p == -1) {
			link[cur] = 0;
		} else {
			int q = next[p][c];
			if (len[p] + 1 == len[q]) {
				link[cur] = q;
			} else {
				int clone = sz++;
				len[clone] = len[p] + 1;
				link[clone] = link[q];
				for (int i = 0; i < 26; i++) next[clone][i] = next[q][i];

				while (p != -1 and next[p][c] == q) {
					next[p][c] = clone;
					p = link[p];
				}

				link[q] = link[cur] = clone;
			}
		}
		last = cur;
	}

	int walk(string& S) {
		int u = 0;
		for (char ch : S) {
			int c = ch - 'a';
			if (!next[u][c]) return -1;
			u = next[u][c];
		}
		return u;
	}
};

struct Query {
	int k, L, id;
};

vector<int> g[2*MAX];
vector<int> occ[2*MAX];
vector<Query> qs[2*MAX];

void merge_vec(vector<int>& a, vector<int>& b) {
	if (b.empty()) return;
	if (a.empty()) { a.swap(b); return; }

	int old = (int)a.size();
	a.insert(a.end(), all(b));
	inplace_merge(a.begin(), a.begin() + old, a.end());
	b.clear();
}

int solve() {
	string s; cin >> s;
	int n = (int)s.size();

	sam::init();
	vector<int> pref_state(n);

	for (int i = 0; i < n; i++) {
		sam::add(s[i] - 'a');
		pref_state[i] = sam::last;
	}

	int SZ = sam::sz;
	for (int i = 0; i < SZ; i++) {
		g[i].clear();
		occ[i].clear();
		qs[i].clear();
	}

	for (int v = 1; v < SZ; v++) g[sam::link[v]].push_back(v);
	for (int i = 0; i < n; i++) occ[pref_state[i]].push_back(i);

	int q; cin >> q;
	vector<int> ans(q, -1);

	for (int id = 0; id < q; id++) {
		int k; string m; cin >> k >> m;
		int v = sam::walk(m);
		if (v == -1) ans[id] = -1;
		else qs[v].push_back({k, (int)m.size(), id});
	}

	// iterative dfs order -> postorder by reversing
	vector<int> order;
	order.reserve(SZ);
	vector<int> st = {0};

	while (!st.empty()) {
		int v = st.back(); st.pop_back();
		order.push_back(v);
		for (int u : g[v]) st.push_back(u);
	}

	for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
		int v = order[idx];

		// small-to-large: keep biggest child vector in occ[v]
		int big = v;
		for (int u : g[v]) {
			if (occ[u].size() > occ[big].size()) big = u;
		}
		if (big != v) swap(occ[v], occ[big]);

		for (int u : g[v]) merge_vec(occ[v], occ[u]);

		if (!qs[v].empty()) {
			auto& p = occ[v];
			int msz = (int)p.size();
			for (auto qu : qs[v]) {
				if (msz < qu.k) {
					ans[qu.id] = -1;
					continue;
				}
				int k = qu.k, L = qu.L;
				int best = (ll)4e18;
				for (int i = 0; i + k - 1 < msz; i++) {
					best = min(best, p[i + k - 1] - p[i] + L);
				}
				ans[qu.id] = best;
			}
		}
	}

	for (int i = 0; i < q; i++) cout << ans[i] << endl;
	return 0;
}

signed main() {
	_;
	int t = 1; //cin >> t;
	while (t--) solve();
	return 0;
}
