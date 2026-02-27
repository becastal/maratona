#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 4e5+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26], vis[2*MAX], cont[2*MAX], ocur[2*MAX];
	int sz, last;

	void init(int reset = 0) {
		if (reset) {
			for (int i = 0; i <= sz; i++) {
				len[i] = link[i] = vis[i] = 0;
				for (int j = 0; j < 26; j++) {
					next[i][j] = 0;
				}
			}
		}

		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}

	void add(int c) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		ocur[cur] = 1;

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

	void processa() {
		for (int i = 1; i < sz; i++) {
			int a = len[link[i]], b = len[i];
			cont[a + 1]++, cont[b + 1]--;
		}

		vector<int> U(sz-1);
		iota(all(U), 1);
		sort(all(U), [&](int a, int b) {
			return len[a] > len[b];
		});

		for (int u : U) {
			ocur[link[u]] += ocur[u];
		}

		for (int i = 1; i <= sz; i++) {
			cont[i] += cont[i-1];
		}
	}
};
const int MOD = 998244353;

int solve(int reset) {
	string S; cin >> S;
	int k, n = (int)S.size(); cin >> k;

	sam::init(reset);
	for (char c : S) {
		sam::add(c - 'a');
	}
	sam::processa();


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

