#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e5+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26], res[2*MAX], cont[2*MAX];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		res[cur] = t;
		cont[cur] = 1;

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
				res[clone] = res[q];
				len[clone] = len[p] + 1;
				link[clone] = link[q];
				for (int i = 0; i < 26; i++) {
					next[clone][i] = next[q][i];
				}

				while (p != -1 and next[p][c] == q) {
					next[p][c] = clone;
					p = link[p];
				}

				link[q] = link[cur] = clone;
			}
		}
		last = cur;
	}

	array<int, 2> contem(string& S) {
		int u = 0;
		for (char c : S) {
			c -= 'a';
			if (next[u][c] == 0) return {0, -1};
			u = next[u][c];
		}
		return {1, u};
	}

	void processa() {
		vector<int> U(sz);
		iota(all(U), 0);

		sort(all(U), [&](int a, int b) { return len[a] > len[b]; });
		for (int u : U) if (link[u] != -1) {
			cont[link[u]] += cont[u];
		}
	}

	array<int, 2> dfs() {
		array<int, 2> ret = {-1, -1};

		vector<int> vis(sz);	
		stack<int> St; St.push(0);
		while (St.size()) {
			int u = St.top(); St.pop();
			array<int, 2> agr = {len[u], res[u] - len[u] + 1};
			if (u and cont[u] > 1) ret = max(ret, agr);

			for (int c = 0; c < 26; c++) if (next[u][c] and !vis[next[u][c]]) {
				int v = next[u][c];
				St.push(v);	
				vis[v] = 1;
			}
		}

		return ret;
	}
};

int solve() {
	string T; cin >> T;
	sam::init();

	for (int i = 0; i < (int)T.size(); i++) {
		sam::add(T[i] - 'a', i);	
	}
	sam::processa();

	array<int, 2> res = sam::dfs();

	if (res[0] == -1) {
		return cout << -1 << endl, 0;
	}

	cout << T.substr(res[1], res[0]) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

