#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e5+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26]; 
	int pos[2*MAX], ocor[2*MAX], quant[2*MAX], res[2*MAX];
	int sz, last;

	void init(int reset = 0) {
		if (reset) {
			for (int i = 0; i <= sz; i++) {
				len[i] = 0, link[i] = 0;
				pos[i] = ocor[i] = quant[i] = res[i] = 0;
				for (int j = 0; j < 26; j++) {
					next[i][j] = 0;
				}
			}
		}

		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		pos[cur] = t;
		ocor[cur] = 1;

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
				pos[clone] = pos[q];
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

	void processa() {
		vector<int> U(sz);
		iota(all(U), 0);

		sort(all(U), [&](int a, int b) { return len[a] > len[b]; });
		for (int u : U) if (link[u] != -1) {
			ocor[link[u]] += ocor[u];
			quant[u] = len[u] - len[link[u]];
			res[ocor[u]] += quant[u] * ocor[u];
		}
	}
};

int solve(int reset) {
	string T; cin >> T;
	int n = (int)T.size();
	sam::init(reset);

	for (int i = 0; i < n; i++) {
		sam::add(T[i] - 'a', i);
	}
	sam::processa();

	for (int i = n-1; i >= 1; i--) {
		sam::res[i] += sam::res[i + 1];		
	}

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << sam::res[x] << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	for (int i = 0; i < t; i++) {
		solve(!!i);
	}
    
    return(0);
}


