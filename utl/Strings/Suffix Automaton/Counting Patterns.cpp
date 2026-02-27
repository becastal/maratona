#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 5e5+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26], cont[2*MAX];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c) {
		int cur = sz++;
		len[cur] = len[last] + 1;
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

	void processa_cont() {
		vector<int> U(sz);
		iota(all(U), 0);
		sort(all(U), [&](int i, int j) {
			return len[i] > len[j];
		});

		for (int u : U) if (link[u] != -1) {
			cont[link[u]] += cont[u];
		}
	}
};

int solve() {
	string T; cin >> T;
	sam::init();

	for (char c : T) {
		sam::add(c - 'a');	
	}
	sam::processa_cont();

	int q; cin >> q;
	while (q--) {
		string S; cin >> S;

		auto [ok, u] = sam::contem(S);
		if (!ok) {
			cout << 0 << endl;
			continue;
		}

		cout << sam::cont[u] << endl;
	}

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

