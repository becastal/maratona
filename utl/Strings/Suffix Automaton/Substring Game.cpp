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
	int len[2*MAX], link[2*MAX], next[2*MAX][26], vis[2*MAX], dp[2*MAX];
	int sz, last;

	void init(int reset = 0) {
		if (reset) {
			for (int i = 0; i <= sz; i++) {
				len[i] = link[i] = vis[i] = dp[i] = 0;
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

	
	int dfs(int u) {
		if (vis[u]) return dp[u];
		vis[u] = 1;

		int perdedora = 1;
		for (int c = 0; c < 26; c++) {
			perdedora &= !next[u][c];
		}

		if (perdedora) return dp[u] = 0;

		int ganho = 0;
		for (int c = 0; c < 26; c++) if (next[u][c]) {
			int v = next[u][c];
			ganho |= !dfs(v);	
		}
		return dp[u] = ganho;
	}
};

int solve(int reset = 0) {
	string S; cin >> S;

	sam::init(reset);
	for (char c : S) {
		sam::add(c - 'a');
	}
	cout << (sam::dfs(0) ? "Alice" : "Bob") << endl;

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

