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
	int res[2*MAX], ocor[2*MAX], quant[2*MAX], dp[2*MAX];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
		memset(dp, -1, sizeof(dp));
	}
	
	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		res[cur] = t;
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

	int calc(int u) {
		if (dp[u] != -1) return dp[u];

		dp[u] = ocor[u];
		for (int c = 0; c < 26; c++) if (next[u][c]) {
			dp[u] += calc(next[u][c]);
		}
		return dp[u];
	}
	
	string kesima(int k) {
		int u = 0;

		string R = "";
		while (k) {
			for (int c = 0; c < 26; c++) if (next[u][c]) {
				int agr = calc(next[u][c]);
				if (k > agr) {
					k -= agr;
				} else {
					R.push_back(char('a' + c));	
					if (k <= ocor[next[u][c]]) return R;
					k -= ocor[next[u][c]];
					u = next[u][c];
					break;
				}
			}
		}
		
		return R;
	};

	void processa() {
		vector<int> U(sz);
		iota(all(U), 0);

		sort(all(U), [&](int a, int b) { return len[a] > len[b]; });
		for (int u : U) if (link[u] != -1) {
			ocor[link[u]] += ocor[u];
			quant[u] = len[u] - len[link[u]];
		}
	}
};

int solve() {
	string T; cin >> T;
	int k, n = (int)T.size(); cin >> k;
	sam::init();

	for (int i = 0; i < n; i++) {
		sam::add(T[i] - 'a', i);
	}

	sam::processa();
	cout << sam::kesima(k) << endl;

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

